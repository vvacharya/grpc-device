functions_override_metadata = {
}

functions_validation_suppressions = {
}

nifpga_array_functions = ['WriteArrayI16', 'WriteArrayU16', 
                          'WriteArrayI64', 'WriteArrayU64',
                          'WriteArrayI16Stream', 'WriteArrayU16Stream',
                          'WriteArrayI64Stream', 'WriteArrayU64Stream']

for function_name in nifpga_array_functions:
    functions_validation_suppressions[function_name] = {
        "parameters": {
            # We shipped this way, fixing it would be a breaking change
            "array": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    }
