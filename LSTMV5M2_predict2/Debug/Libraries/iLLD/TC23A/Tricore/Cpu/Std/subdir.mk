################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC23A/Tricore/Cpu/Std/IfxCpu.c 

OBJS += \
./Libraries/iLLD/TC23A/Tricore/Cpu/Std/IfxCpu.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC23A/Tricore/Cpu/Std/IfxCpu.src 

C_DEPS += \
./Libraries/iLLD/TC23A/Tricore/Cpu/Std/IfxCpu.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC23A/Tricore/Cpu/Std/%.src: ../Libraries/iLLD/TC23A/Tricore/Cpu/Std/%.c Libraries/iLLD/TC23A/Tricore/Cpu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc23x "-fD:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict2/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC23A/Tricore/Cpu/Std/%.o: ./Libraries/iLLD/TC23A/Tricore/Cpu/Std/%.src Libraries/iLLD/TC23A/Tricore/Cpu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


