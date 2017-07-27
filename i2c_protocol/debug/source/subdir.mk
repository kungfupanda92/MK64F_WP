################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/boards/frdmk64f/driver_examples/i2c/interrupt_transfer/i2c_interrupt_transfer.c 

OBJS += \
./source/i2c_interrupt_transfer.o 

C_DEPS += \
./source/i2c_interrupt_transfer.d 


# Each subdirectory must supply rules for building sources it contributes
source/i2c_interrupt_transfer.o: H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/boards/frdmk64f/driver_examples/i2c/interrupt_transfer/i2c_interrupt_transfer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../../../../../../../CMSIS/Include -I../../../../../../../devices -I../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../devices/MK64F12/utilities -I../../../../.. -I../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"source/i2c_interrupt_transfer.d" -MT"source/i2c_interrupt_transfer.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


