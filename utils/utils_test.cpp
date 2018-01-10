#include "utils.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE utils test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_type_name_valid_mangled_name) {
	std::string expected("type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE demangled_type: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >");
	BOOST_REQUIRE_EQUAL(expected, utils::get_type_name(expected));
}
