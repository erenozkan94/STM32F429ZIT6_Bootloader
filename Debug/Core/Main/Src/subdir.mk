################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Main/Src/main.c \
../Core/Main/Src/stm32f4xx_hal_msp.c \
../Core/Main/Src/stm32f4xx_it.c \
../Core/Main/Src/syscalls.c \
../Core/Main/Src/sysmem.c \
../Core/Main/Src/system_stm32f4xx.c 

OBJS += \
./Core/Main/Src/main.o \
./Core/Main/Src/stm32f4xx_hal_msp.o \
./Core/Main/Src/stm32f4xx_it.o \
./Core/Main/Src/syscalls.o \
./Core/Main/Src/sysmem.o \
./Core/Main/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Main/Src/main.d \
./Core/Main/Src/stm32f4xx_hal_msp.d \
./Core/Main/Src/stm32f4xx_it.d \
./Core/Main/Src/syscalls.d \
./Core/Main/Src/sysmem.d \
./Core/Main/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Main/Src/%.o Core/Main/Src/%.su Core/Main/Src/%.cyclo: ../Core/Main/Src/%.c Core/Main/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/CAN" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/CAN/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Bootloader/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Main/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Main" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Bootloader" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Main-2f-Src

clean-Core-2f-Main-2f-Src:
	-$(RM) ./Core/Main/Src/main.cyclo ./Core/Main/Src/main.d ./Core/Main/Src/main.o ./Core/Main/Src/main.su ./Core/Main/Src/stm32f4xx_hal_msp.cyclo ./Core/Main/Src/stm32f4xx_hal_msp.d ./Core/Main/Src/stm32f4xx_hal_msp.o ./Core/Main/Src/stm32f4xx_hal_msp.su ./Core/Main/Src/stm32f4xx_it.cyclo ./Core/Main/Src/stm32f4xx_it.d ./Core/Main/Src/stm32f4xx_it.o ./Core/Main/Src/stm32f4xx_it.su ./Core/Main/Src/syscalls.cyclo ./Core/Main/Src/syscalls.d ./Core/Main/Src/syscalls.o ./Core/Main/Src/syscalls.su ./Core/Main/Src/sysmem.cyclo ./Core/Main/Src/sysmem.d ./Core/Main/Src/sysmem.o ./Core/Main/Src/sysmem.su ./Core/Main/Src/system_stm32f4xx.cyclo ./Core/Main/Src/system_stm32f4xx.d ./Core/Main/Src/system_stm32f4xx.o ./Core/Main/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Main-2f-Src

