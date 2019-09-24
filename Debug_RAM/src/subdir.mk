################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/FlexCAN.c" \
"../src/LPSPI.c" \
"../src/clocks_and_modes.c" \
"../src/main.c" \

C_SRCS += \
../src/FlexCAN.c \
../src/LPSPI.c \
../src/clocks_and_modes.c \
../src/main.c \

OBJS_OS_FORMAT += \
./src/FlexCAN.o \
./src/LPSPI.o \
./src/clocks_and_modes.o \
./src/main.o \

C_DEPS_QUOTED += \
"./src/FlexCAN.d" \
"./src/LPSPI.d" \
"./src/clocks_and_modes.d" \
"./src/main.d" \

OBJS += \
./src/FlexCAN.o \
./src/LPSPI.o \
./src/clocks_and_modes.o \
./src/main.o \

OBJS_QUOTED += \
"./src/FlexCAN.o" \
"./src/LPSPI.o" \
"./src/clocks_and_modes.o" \
"./src/main.o" \

C_DEPS += \
./src/FlexCAN.d \
./src/LPSPI.d \
./src/clocks_and_modes.d \
./src/main.d \


# Each subdirectory must supply rules for building sources it contributes
src/FlexCAN.o: ../src/FlexCAN.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/FlexCAN.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/FlexCAN.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LPSPI.o: ../src/LPSPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/LPSPI.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/LPSPI.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/clocks_and_modes.o: ../src/clocks_and_modes.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clocks_and_modes.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/clocks_and_modes.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


