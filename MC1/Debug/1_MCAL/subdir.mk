################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1_MCAL/adc.c \
../1_MCAL/gpio.c \
../1_MCAL/interrupt.c \
../1_MCAL/spi.c \
../1_MCAL/timer.c \
../1_MCAL/twi.c \
../1_MCAL/uart.c 

OBJS += \
./1_MCAL/adc.o \
./1_MCAL/gpio.o \
./1_MCAL/interrupt.o \
./1_MCAL/spi.o \
./1_MCAL/timer.o \
./1_MCAL/twi.o \
./1_MCAL/uart.o 

C_DEPS += \
./1_MCAL/adc.d \
./1_MCAL/gpio.d \
./1_MCAL/interrupt.d \
./1_MCAL/spi.d \
./1_MCAL/timer.d \
./1_MCAL/twi.d \
./1_MCAL/uart.d 


# Each subdirectory must supply rules for building sources it contributes
1_MCAL/%.o: ../1_MCAL/%.c 1_MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


