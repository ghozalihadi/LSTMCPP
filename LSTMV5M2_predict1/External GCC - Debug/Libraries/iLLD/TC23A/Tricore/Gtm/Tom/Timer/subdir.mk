################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c 

OBJS += \
./Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o 

C_DEPS += \
./Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/%.o: ../Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/%.c Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

