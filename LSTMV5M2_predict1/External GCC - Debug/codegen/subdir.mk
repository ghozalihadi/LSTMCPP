################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../codegen/lstmForward.c \
../codegen/my_predict_mode1.c \
../codegen/my_predict_mode1_data.c \
../codegen/my_predict_mode1_initialize.c \
../codegen/my_predict_mode1_terminate.c \
../codegen/predict.c \
../codegen/stubs.c 

OBJS += \
./codegen/lstmForward.o \
./codegen/my_predict_mode1.o \
./codegen/my_predict_mode1_data.o \
./codegen/my_predict_mode1_initialize.o \
./codegen/my_predict_mode1_terminate.o \
./codegen/predict.o \
./codegen/stubs.o 

C_DEPS += \
./codegen/lstmForward.d \
./codegen/my_predict_mode1.d \
./codegen/my_predict_mode1_data.d \
./codegen/my_predict_mode1_initialize.d \
./codegen/my_predict_mode1_terminate.d \
./codegen/predict.d \
./codegen/stubs.d 


# Each subdirectory must supply rules for building sources it contributes
codegen/%.o: ../codegen/%.c codegen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


