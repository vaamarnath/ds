#ifndef __utils_h__
#define __utils_h__

#include <string>
#include <stdexcept>
#include <typeinfo>
#include <cxxabi.h>

namespace utils {

template <typename T>
std::string get_type_name(T& input) {
	const std::type_info &ti = typeid(input);
	std::string type_info_name;
	int status;
	char *demangled_name = abi::__cxa_demangle(ti.name(), 0, 0, &status);
	if (status == 0) {
		type_info_name = "type: " + std::string(ti.name()) + " demangled_type: " + std::string(demangled_name);
	} else if (status == -1) {
		throw std::runtime_error("memory allocation failure");
	} else if (status == -2) {
		throw std::runtime_error("mangled_name is not valid name under the C++ ABI mangling rules");
	} else if (status == -3) {
		throw std::runtime_error("invalid arguments passed");
	}
	return type_info_name;
}

}

#endif
