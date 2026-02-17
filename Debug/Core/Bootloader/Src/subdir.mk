################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Bootloader/Src/Bootloader.c 

OBJS += \
./Core/Bootloader/Src/Bootloader.o 

C_DEPS += \
./Core/Bootloader/Src/Bootloader.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Bootloader/Src/%.o Core/Bootloader/Src/%.su Core/Bootloader/Src/%.cyclo: ../Core/Bootloader/Src/%.c Core/Bootloader/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/CAN" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/CAN/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Bootloader/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Main/Inc" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Main" -I"C:/Users/RFTRYazilim/Desktop/ForkFile/STM32F429ZIT6_Bootloader_Firmware/Core/Bootloader" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Bootloader-2f-Src

clean-Core-2f-Bootloader-2f-Src:
	-$(RM) ./Core/Bootloader/Src/Bootloader.cyclo ./Core/Bootloader/Src/Bootloader.d ./Core/Bootloader/Src/Bootloader.o ./Core/Bootloader/Src/Bootloader.su

.PHONY: clean-Core-2f-Bootloader-2f-Src

