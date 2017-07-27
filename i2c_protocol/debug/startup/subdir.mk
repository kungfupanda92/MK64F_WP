################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/devices/MK64F12/system_MK64F12.c 

S_UPPER_SRCS += \
H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/devices/MK64F12/gcc/startup_MK64F12.S 

OBJS += \
./startup/startup_MK64F12.o \
./startup/system_MK64F12.o 

C_DEPS += \
./startup/system_MK64F12.d 

S_UPPER_DEPS += \
./startup/startup_MK64F12.d 


# Each subdirectory must supply rules for building sources it contributes
startup/startup_MK64F12.o: H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/devices/MK64F12/gcc/startup_MK64F12.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -x assembler-with-cpp -DDEBUG -D__STARTUP_CLEAR_BSS -mapcs -MMD -MP -MF"startup/startup_MK64F12.d" -MT"startup/startup_MK64F12.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup/system_MK64F12.o: H:/My\ Study/Embedded\ Linux/FRDM-K64F/SDK_2.1_MK64FN1M0xxx12/devices/MK64F12/system_MK64F12.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../../../../../../../CMSIS/Include -I../../../../../../../devices -I../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../devices/MK64F12/utilities -I../../../../.. -I../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"startup/system_MK64F12.d" -MT"startup/system_MK64F12.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


