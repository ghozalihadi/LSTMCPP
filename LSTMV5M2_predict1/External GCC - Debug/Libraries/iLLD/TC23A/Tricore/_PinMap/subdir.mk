################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxAsclin_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxCcu6_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEray_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEth_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGpt12_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGtm_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxMultican_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxPort_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxQspi_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxScu_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSent_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSmu_PinMap.c \
../Libraries/iLLD/TC23A/Tricore/_PinMap/IfxVadc_PinMap.c 

OBJS += \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxAsclin_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxCcu6_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEray_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEth_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGpt12_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGtm_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxMultican_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxPort_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxQspi_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxScu_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSent_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSmu_PinMap.o \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxVadc_PinMap.o 

C_DEPS += \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxAsclin_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxCcu6_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEray_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxEth_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGpt12_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxGtm_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxMultican_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxPort_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxQspi_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxScu_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSent_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxSmu_PinMap.d \
./Libraries/iLLD/TC23A/Tricore/_PinMap/IfxVadc_PinMap.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC23A/Tricore/_PinMap/%.o: ../Libraries/iLLD/TC23A/Tricore/_PinMap/%.c Libraries/iLLD/TC23A/Tricore/_PinMap/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


