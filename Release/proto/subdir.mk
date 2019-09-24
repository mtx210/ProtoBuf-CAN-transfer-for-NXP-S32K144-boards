################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../proto/pb_common.c" \
"../proto/pb_decode.c" \
"../proto/pb_encode.c" \
"../proto/simpleNano.pb.c" \

C_SRCS += \
../proto/pb_common.c \
../proto/pb_decode.c \
../proto/pb_encode.c \
../proto/simpleNano.pb.c \

OBJS_OS_FORMAT += \
./proto/pb_common.o \
./proto/pb_decode.o \
./proto/pb_encode.o \
./proto/simpleNano.pb.o \

C_DEPS_QUOTED += \
"./proto/pb_common.d" \
"./proto/pb_decode.d" \
"./proto/pb_encode.d" \
"./proto/simpleNano.pb.d" \

OBJS += \
./proto/pb_common.o \
./proto/pb_decode.o \
./proto/pb_encode.o \
./proto/simpleNano.pb.o \

OBJS_QUOTED += \
"./proto/pb_common.o" \
"./proto/pb_decode.o" \
"./proto/pb_encode.o" \
"./proto/simpleNano.pb.o" \

C_DEPS += \
./proto/pb_common.d \
./proto/pb_decode.d \
./proto/pb_encode.d \
./proto/simpleNano.pb.d \


# Each subdirectory must supply rules for building sources it contributes
proto/pb_common.o: ../proto/pb_common.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@proto/pb_common.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "proto/pb_common.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

proto/pb_decode.o: ../proto/pb_decode.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@proto/pb_decode.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "proto/pb_decode.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

proto/pb_encode.o: ../proto/pb_encode.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@proto/pb_encode.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "proto/pb_encode.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

proto/simpleNano.pb.o: ../proto/simpleNano.pb.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@proto/simpleNano.pb.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "proto/simpleNano.pb.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


