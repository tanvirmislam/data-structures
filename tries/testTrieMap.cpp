#include "TrieUsingMap.h"
#include <iostream>

using namespace std;

int main() {
	Trie tr;

	tr.insert("abcd");
	tr.insert("bed");
	tr.insert("ab");
	tr.insert("czkl");

	cout << "Does czkl exist? " << (tr.search("abcd") ? "YES" : "NO") << endl;
	
	return 0;
}