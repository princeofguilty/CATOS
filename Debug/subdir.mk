################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_Prog.c \
../LCD_Prog.c \
../Prog.c \
../RTO_program.c \
../boot.c 

C_DEPS += \
./ADC_prog.d \
./DIO_Prog.d \
./LCD_Prog.d \
./Prog.d \
./RTO_program.d \
./boot.d 

OBJS += \
./ADC_prog.o \
./DIO_Prog.o \
./LCD_Prog.o \
./Prog.o \
./RTO_program.o \
./boot.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


