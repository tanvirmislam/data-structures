#ifndef __TRIE_USING_ARRAY___
#define __TRIE_USING_ARRAY___

#include <string>

#define TOTAL_CHARS 128

class TrieNode {
public:
	// Holds an array of TrieNodes
	// Traverse from one node to the other to search words
	TrieNode* children[TOTAL_CHARS];
	// Holds a boolean value to indicate end of word
	bool isEndOfWord;

	TrieNode() {
		for (int i = 0; i < TOTAL_CHARS; i++) {
			children[i] = nullptr;
		}
		isEndOfWord = false;
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() : root(new TrieNode()) {}

	void insert(std::string word) {
		TrieNode* at = root;

		for (int i = 0; i < word.length(); i++) {
			if (at->children[word[i]] == nullptr) {
				// new entry
				at->children[word[i]] = new TrieNode();
			}

			// traverse to the next node
			at = at->children[word[i]];
		}

		at->isEndOfWord = true;
	}

	bool search(std::string str) {
		TrieNode* at = root;

		for (int i = 0; i < str.length(); i++) {
			if (at->children[str[i]] == nullptr) {
				// Doesn't exist
				return false;
			}

			// traverse to the next node
			at = at->children[str[i]];
		}

		return (at != nullptr && at->isEndOfWord == true);
	}
};

#endif