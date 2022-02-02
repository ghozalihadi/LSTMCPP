################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxAsclin_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxCcu6_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxCpu_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxDma_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxEray_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxFlash_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxGtm_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxMtu_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxMultican_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxPort_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxQspi_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxScu_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxSent_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxSmu_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxSrc_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxStm_cfg.c \
../Libraries/iLLD/TC23A/Tricore/_Impl/IfxVadc_cfg.c 

OBJS += \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxAsclin_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxCcu6_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxCpu_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxDma_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxEray_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxFlash_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxGtm_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxMtu_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxMultican_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxPort_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxQspi_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxScu_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSent_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSmu_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSrc_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxStm_cfg.o \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxVadc_cfg.o 

C_DEPS += \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxAsclin_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxCcu6_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxCpu_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxDma_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxEray_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxFlash_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxGtm_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxMtu_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxMultican_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxPort_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxQspi_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxScu_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSent_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSmu_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxSrc_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxStm_cfg.d \
./Libraries/iLLD/TC23A/Tricore/_Impl/IfxVadc_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC23A/Tricore/_Impl/%.o: ../Libraries/iLLD/TC23A/Tricore/_Impl/%.c Libraries/iLLD/TC23A/Tricore/_Impl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


