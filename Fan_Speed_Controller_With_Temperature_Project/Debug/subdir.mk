################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../fan_speed_controller_with_temperature.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../motor.c \
../pwm.c 

OBJS += \
./adc.o \
./fan_speed_controller_with_temperature.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./motor.o \
./pwm.o 

C_DEPS += \
./adc.d \
./fan_speed_controller_with_temperature.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./motor.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


