################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.c \
../Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.c 

OBJS += \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.o \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.o 

C_DEPS += \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.d \
./Libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Service/CpuGeneric/SysSe/Math/%.o: ../Libraries/Service/CpuGeneric/SysSe/Math/%.c Libraries/Service/CpuGeneric/SysSe/Math/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict1/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


