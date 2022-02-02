################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm.c \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Cmu.c \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Dpll.c \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tbu.c \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tim.c \
../Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tom.c 

OBJS += \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm.o \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Cmu.o \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Dpll.o \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tbu.o \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tim.o \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tom.o 

C_DEPS += \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm.d \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Cmu.d \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Dpll.d \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tbu.d \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tim.d \
./Libraries/iLLD/TC23A/Tricore/Gtm/Std/IfxGtm_Tom.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC23A/Tricore/Gtm/Std/%.o: ../Libraries/iLLD/TC23A/Tricore/Gtm/Std/%.c Libraries/iLLD/TC23A/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


