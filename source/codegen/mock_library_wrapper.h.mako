<%
import common_helpers
import handler_helpers

config = data['config']
functions = data['functions']

service_class_prefix = config["service_class_prefix"]
namespace_prefix = "ni::" + config["namespace_component"] + "::grpc"
include_guard_name = handler_helpers.get_include_guard_name(config, "_MOCK_LIBRARY_WRAPPER_H")
%>\
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryWrapper for ${config["driver_name"]}
//---------------------------------------------------------------------
## Define section
#ifndef ${include_guard_name}
#define ${include_guard_name}

## Include section
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "${config["module_name"]}_library_wrapper.h"

namespace ni {
namespace tests {
namespace unit {
namespace ${config["namespace_component"]} {
namespace grpc {

namespace driverNamespace = ${namespace_prefix};

class ${service_class_prefix}MockLibraryWrapper : public driverNamespace::${service_class_prefix}LibraryWrapper {
 public:
  MOCK_METHOD(::grpc::Status, check_function_exists, (std::string functionName), (override));
% for method_name in handler_helpers.filter_api_functions(functions):
<%
  f = functions[method_name]
  parameters = f['parameters']
  handler_helpers.sanitize_names(parameters)
  return_type = f['returns']
%>\
% if not common_helpers.has_unsupported_parameter(f):
  MOCK_METHOD(${return_type}, ${method_name}, (${handler_helpers.create_params(parameters)}), (override));
% endif
%endfor
};

}  // namespace grpc
}  // namespace ${config["namespace_component"]}
}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // ${include_guard_name}
