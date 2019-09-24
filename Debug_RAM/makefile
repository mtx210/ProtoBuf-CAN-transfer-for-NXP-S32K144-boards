################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 7
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FlexCAN_s32k144.elf \

EXECUTABLES_QUOTED += \
"FlexCAN_s32k144.elf" \

EXECUTABLES_OS_FORMAT += \
FlexCAN_s32k144.elf \

SECONDARY_SIZE += \
FlexCAN_s32k144.siz \
FlexCAN_s32k144.siz \

SECONDARY_SIZE_QUOTED += \
"FlexCAN_s32k144.siz" \
"FlexCAN_s32k144.siz" \

SECONDARY_SIZE_OS_FORMAT += \
FlexCAN_s32k144.siz \
FlexCAN_s32k144.siz \

SECONDARY_SIZE += \
FlexCAN_s32k144.siz \
FlexCAN_s32k144.siz \

SECONDARY_SIZE_QUOTED += \
"FlexCAN_s32k144.siz" \
"FlexCAN_s32k144.siz" \

SECONDARY_SIZE_OS_FORMAT += \
FlexCAN_s32k144.siz \
FlexCAN_s32k144.siz \


# All Target
all: warning-messages explicit-dependencies FlexCAN_s32k144.elf secondary-outputs

# Tool invocations
FlexCAN_s32k144.elf: $(OBJS) C:/Users/MTXX/workspaceS32DS.ARM.2018.R1/FlexCAN_s32k144/FlexCAN_s32k144/Project_Settings/Linker_Files/S32K1xx_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #8 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "FlexCAN_s32k144.elf" "@FlexCAN_s32k144.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

FlexCAN_s32k144.siz: $(EXECUTABLES)
	@echo 'Executing target #9 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*.d  ./*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

