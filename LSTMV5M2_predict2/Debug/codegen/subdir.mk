################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../codegen/lstmForward.c \
../codegen/my_predict_mode2.c \
../codegen/my_predict_mode2_data.c \
../codegen/my_predict_mode2_initialize.c \
../codegen/my_predict_mode2_terminate.c \
../codegen/predict.c \
../codegen/stubs.c 

OBJS += \
./codegen/lstmForward.o \
./codegen/my_predict_mode2.o \
./codegen/my_predict_mode2_data.o \
./codegen/my_predict_mode2_initialize.o \
./codegen/my_predict_mode2_terminate.o \
./codegen/predict.o \
./codegen/stubs.o 

COMPILED_SRCS += \
./codegen/lstmForward.src \
./codegen/my_predict_mode2.src \
./codegen/my_predict_mode2_data.src \
./codegen/my_predict_mode2_initialize.src \
./codegen/my_predict_mode2_terminate.src \
./codegen/predict.src \
./codegen/stubs.src 

C_DEPS += \
./codegen/lstmForward.d \
./codegen/my_predict_mode2.d \
./codegen/my_predict_mode2_data.d \
./codegen/my_predict_mode2_initialize.d \
./codegen/my_predict_mode2_terminate.d \
./codegen/predict.d \
./codegen/stubs.d 


# Each subdirectory must supply rules for building sources it contributes
codegen/%.src: ../codegen/%.c codegen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc23x "-fD:/Softwares/Installed/AURIX-Studio-1.5.4/AURIX-v1.5.4-workspace/LSTMV5M2_predict2/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

codegen/%.o: ./codegen/%.src codegen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


