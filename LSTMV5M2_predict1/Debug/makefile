################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include codegen/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Gtm/Tom/Timer/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Cpu/CStart/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC23A/Tricore/Asclin/Asc/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Demo_Illd/subdir.mk
-include Configurations/Debug/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LSTMV5M2_predict1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
LSTMV5M2_predict1.siz \


# All Target
all: main-build

# Main-build Target
main-build: LSTMV5M2_predict1.elf secondary-outputs

# Tool invocations
LSTMV5M2_predict1.elf: $(OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -lrt -lfp_fpu -lcs_fpu  -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="LSTMV5M2_predict1.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --exceptions --strict --anachronisms --force-c++ -Ctc23x   -o"LSTMV5M2_predict1.elf" -Wl-o"LSTMV5M2_predict1.hex:IHEX" --lsl-core=vtc  --lsl-file=../Lcf_Tasking_Tricore_Tc.lsl $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

LSTMV5M2_predict1.siz: LSTMV5M2_predict1.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "LSTMV5M2_predict1.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
