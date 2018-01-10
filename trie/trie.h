#ifndef __trie_h__
#define __trie_h__

#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

#include "utils/utils.h"

namespace ds {

namespace trie {

template <typename T>
class trie {
	typedef std::unordered_map<typename T::value_type, std::shared_ptr<trie<T>>> child_type_t;
	typedef std::shared_ptr<child_type_t> child_map_type;
	child_map_type m_children;
	bool m_is_leaf;

public:
	trie() = delete;
	trie(bool is_leaf);
	~trie() = default;

	bool insert(const T& value);
};

template <typename T>
trie<T>::trie(bool is_leaf) : m_is_leaf(is_leaf) {
	if (!is_leaf) {
		m_children = std::make_shared<child_type_t>();
	}
}

template <typename T>
bool trie<T>::insert(const T& value) {
	if (value.empty()) {
		return false;
	} else {
		decltype(*this) current_node = *this;
		for (auto& iter : value) {
			try {
				current_node = *(current_node.m_children->at(iter));
			} catch (std::out_of_range& e) {
				std::shared_ptr<trie<T>> child = std::make_shared<trie<T>>(true);
				std::cerr << iter << " ";
				if (current_node.m_is_leaf) {
					current_node.m_children = std::make_shared<child_type_t>();
					current_node.m_is_leaf = false;
				}
				current_node.m_children->insert({iter, child});
			}
		}
	}
	return false;
}

} // namespace trie

} // namespace ds

#endif
