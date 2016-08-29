################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
sensorlib/bq27441g1.obj: C:/EK-TM4C129/sensorlib/bq27441g1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/CCSV6/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 --include_path="C:/CCSV6/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --include_path="C:/EK-TM4C129/examples/boards/ek-tm4c1294xl-boostxl-battpack" --include_path="C:/EK-TM4C129" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=TARGET_IS_TM4C129_RA0 --define=UART_BUFFERED --diag_warning=225 --display_error_number --diag_wrap=off --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="sensorlib/bq27441g1.d" --obj_directory="sensorlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


