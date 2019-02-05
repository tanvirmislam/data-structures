#include "Hashmap-lp.h"
#include <iostream>

using namespace std;


template <typename K, typename V>
std::ostream& operator<< (std::ostream& out, const HashMap<K, V>& hm) {
	if (!hm.isEmpty()) {
		out << "[\n";
		out << hm.toString();
    	out << "]\n";
	}
	return out;
}

int main() {
	HashMap<int,int> hm;

	hm.insert(64, -60);	
	hm.insert(15, 99);
	hm.insert(15, 20);
	hm.insert(32, -153);
	hm.remove(32);
	
	cout << hm << endl;
	
	return 0;
}