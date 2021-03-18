################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
recursos/display/%.obj: ../recursos/display/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Users/tulio/Applications/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Users/tulio/Developer/CCS/ProyectoSE" --include_path="/Users/tulio/Applications/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="/Users/tulio/CCS_proyects/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="recursos/display/$(basename $(<F)).d_raw" --obj_directory="recursos/display" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


