#ifndef __TRIE_USING_MAP__
#define __TRIE_USING_MAP__

#include <unordered_map>
#include <string>
#include <utility>

class TrieNode {
public:
	std::unordered_map<char, TrieNode*> nodeMap;
	bool isEndOfWord;

	TrieNode() : isEndOfWord(false) {}
	TrieNode(bool isLeaf) : isEndOfWord(isLeaf) {}

	bool find(char c) {
		nodeMap.find(c) != nodeMap.end();
	}

	bool add(char c) {
		nodeMap.insert(std::make_pair(c, new TrieNode()));
	}

	TrieNode* get(char c) {
		return nodeMap[c];
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() : root(new TrieNode) {}

	void insert(std::string word) {
		TrieNode* current = root;

		for (int i = 0; i < word.length(); i++) {
			if (current->find(word[i]) == false) {
				current->add(word[i]);
			}

			current = current->get(word[i]);
		}

		current->isEndOfWord = true;
	}

	bool search(std::string str) {
		TrieNode* current = root;

		for (int i = 0; i < str.length(); i++) {
			if (current->find(str[i]) == false) {
				return false;
			}
			current = current->get(str[i]);
		}

		return (current != nullptr && current->isEndOfWord == true);
	}
};

#endif