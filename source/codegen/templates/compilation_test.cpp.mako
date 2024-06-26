<%
import service_helpers

config = data['config']
functions = data['functions']

module_name = config["module_name"]
c_function_prefix = config["c_function_prefix"]
%>\
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Compilation test for the ${config["driver_name"]} Metadata
//---------------------------------------------------------------------
#include "${module_name}_library.h"

namespace ${config["namespace_component"]}_grpc {

% for method_name in service_helpers.filter_api_functions(functions, only_mockable_functions=False):
<%
  f = functions[method_name]
  parameters = f['parameters']
  return_type = f['returns']
  parameter_list = service_helpers.create_params(parameters, expand_varargs=True)
  argument_list = ', '.join(p['cppName'] for p in service_helpers.expand_varargs_parameters(parameters) if not p.get("proto_only", False))
  c_name = service_helpers.get_cname(functions, method_name, c_function_prefix)
%>\
% if not service_helpers.is_private_method(f) and not service_helpers.is_restricted_driver_service(config):
${return_type} ${method_name}(${parameter_list})
{
  return ${c_name}(${argument_list});
}

% endif
% endfor
}  // namespace ${config["namespace_component"]}_grpc
