/* main.c                              Copyright NXP 2016
 * 2016 Jul 22 S. Mihalik - Initial version
 * 2016 Sep 12 SM - Updated with SBC init, Node A - B communication
 * 2016 Oct 31 SM- Clocks adjusted for 160 MHz SPLL, updated loop logic
 * 2017 Jul 03 SM- Removed code for: MC33903 on obsolete EVB,
 */

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clocks_and_modes.h"
#include "FlexCAN.h"
#include "LPUART.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "ProtoBuff.h"
#include "simpleNano.pb.h"

int idle_counter = 0;           /* main loop idle counter */
int lpit0_ch0_flag_counter = 0; /* LPIT0 chan 0 timeout counter */

void NVIC_init_IRQs (void) {
  S32_NVIC->ICPR[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
  S32_NVIC->ISER[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: enable IRQ */
  S32_NVIC->IP[48] = 0xA0;             /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}

void WDOG_disable (void){
  WDOG->CNT=0xD928C520; 	/* Unlock watchdog */
  WDOG->TOVAL=0x0000FFFF;	/* Maximum timeout value */
  WDOG->CS = 0x00002100;    /* Disable watchdog */
}

void PORT_init (void) {
  PCC->PCCn[PCC_PORTC_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTC */
  PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORTE */
  PCC->PCCn[PCC_PORTD_INDEX ]|=PCC_PCCn_CGC_MASK;   /* Enable clock for PORTD */
  PORTE->PCR[4] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
  PORTE->PCR[5] |= PORT_PCR_MUX(5); /* Port E5: MUX = ALT5, CAN0_TX */
  PORTD->PCR[16] =  0x00000100;     /* Port D16: MUX = GPIO (to green LED) */
  PTD->PDDR |= 1<<16;               /* Port D16: Data direction = output */
  PORTC->PCR[6]|=PORT_PCR_MUX(2);           /* Port C6: MUX = ALT2,UART1 TX */
  PORTC->PCR[7]|=PORT_PCR_MUX(2);           /* Port C7: MUX = ALT2,UART1 RX */
  PTD->PDDR |= 1<<0;            /* Port D0:  Data Direction= output */
  PORTD->PCR[0] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
}

void LPIT0_init (void) {
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);    /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001;    /* DBG_EN-0: Timer chans stop in Debug mode */
                              /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                              /* SW_RST=0: SW reset does not reset timer chans, regs */
                           /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
  LPIT0->MIER = 0x00000001;   /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
  LPIT0->TMR[0].TVAL = 40000000;    /* Chan 0 Timeout period: 40M clocks */
  LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
                              /* CHAIN=0: channel chaining is disabled */
                              /* MODE=0: 32 periodic counter mode */
                              /* TSOT=0: Timer decrements immediately based on restart */
                              /* TSOI=0: Timer does not stop after timeout */
                              /* TROT=0 Timer will not reload on trigger */
                              /* TRG_SRC=0: External trigger soruce */
                              /* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}

int main(void) {
  WDOG_disable();
  SOSC_init_8MHz();       /* Initialize system oscillator for 8 MHz xtal */
  SPLL_init_160MHz();     /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
  NormalRUNmode_80MHz();  /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
  NVIC_init_IRQs();        /* Enable desired interrupts and priorities */
  LPIT0_init();            /* Initialize PIT0 for 1 second timeout  */
  FLEXCAN0_init();         /* Init FlexCAN0 */
  PORT_init();             /* Configure ports */
  LPUART1_init();

  clearRXDATA();

  LPUART1_transmit_string("==========NODE Alpha==========\n\r");
  #ifdef NODE_A

  for(;;){
  	  char a,b;
  	  int x = 0;
  	  int y = 0;
  	  nanoPB_simpleNano message;
  	  uint8_t buffer[4];
  	  uint8_t empty[4] = {' ',' ',' ',' '};

  	  LPUART1_transmit_string("Input a:   b:\n\r      ");
  	  a = LPUART1_receive_char();
  	  LPUART1_transmit_char(a);
  	  LPUART1_transmit_string("    ");
  	  b = LPUART1_receive_char();
  	  LPUART1_transmit_char(b);
  	  LPUART1_transmit_string("\n\r=====Awaiting response...=====\n\r");

  	  x = a - '0';
  	  y = b - '0';
  	  message.a = x;
  	  message.b = y;

  	  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  	  pb_encode(&stream, nanoPB_simpleNano_fields, &message);

  	  //send it to CAN
  	  FLEXCAN0_transmit_msg(empty);
  	  FLEXCAN0_transmit_msg(buffer);
  }

  #else

  LPUART1_transmit_string("==========NODE Beta===========\n\r");
  LPUART1_transmit_string("==Awaiting data from CAN....==\n\r");

  #endif
}

void LPIT0_Ch0_IRQHandler (void) {
  LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 *//* Perform read-after-write to ensure flag clears before ISR exit */
  lpit0_ch0_flag_counter++;         /* Increment LPIT0 timeout counter */
  if ((CAN0->IFLAG1 >> 4) & 1) {
	#ifdef NODE_A
	  //TODO Node A receive sum
	  FLEXCAN0_receive_sum();

	#else
  	  FLEXCAN0_receive_msg();

	#endif
  }
  PTD->PTOR |= 1<<0;                /* Toggle output on port D0 (blue LED) */
}
