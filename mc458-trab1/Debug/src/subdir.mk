################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bubble.c \
../src/heap.c \
../src/insertion.c \
../src/main.c \
../src/merge.c \
../src/quick.c 

OBJS += \
./src/bubble.o \
./src/heap.o \
./src/insertion.o \
./src/main.o \
./src/merge.o \
./src/quick.o 

C_DEPS += \
./src/bubble.d \
./src/heap.d \
./src/insertion.d \
./src/main.d \
./src/merge.d \
./src/quick.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


