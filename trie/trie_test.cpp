#include "trie.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE trie test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_trie_constructor_string) {
	BOOST_CHECK_NO_THROW(ds::trie::trie<std::string>(false));
}

BOOST_AUTO_TEST_CASE(test_trie_string_empty_word) {
	std::unique_ptr<ds::trie::trie<std::string>> test_trie = nullptr;
	BOOST_REQUIRE_NO_THROW(test_trie = std::unique_ptr<ds::trie::trie<std::string>>(new ds::trie::trie<std::string>(false)));
	BOOST_REQUIRE(test_trie);
	BOOST_CHECK(!test_trie->insert(""));
}

BOOST_AUTO_TEST_CASE(test_trie_string_single_word) {
	std::unique_ptr<ds::trie::trie<std::string>> test_trie = nullptr;
	BOOST_REQUIRE_NO_THROW(test_trie = std::unique_ptr<ds::trie::trie<std::string>>(new ds::trie::trie<std::string>(false)));
	BOOST_REQUIRE(test_trie);
	BOOST_CHECK(test_trie->insert("application"));
}
