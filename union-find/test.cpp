#include "UnionFind.h"
#include <iostream>

using namespace std;

int main() {
	UnionFind uf;

	uf.makeSet(1);
	uf.makeSet(2);
	uf.makeSet(3);
	uf.makeSet(4);
	uf.makeSet(5);
	uf.makeSet(6);
	uf.makeSet(7);

	uf.performUnion(1, 2);
	uf.performUnion(2, 3);
	uf.performUnion(4, 5);
	uf.performUnion(6, 7);
	uf.performUnion(5, 6);
	uf.performUnion(3, 7);

	// All should print 4
	cout << uf.find(1) << endl;
	cout << uf.find(2) << endl;
	cout << uf.find(3) << endl;
	cout << uf.find(4) << endl;
	cout << uf.find(5) << endl;
	cout << uf.find(6) << endl;
	cout << uf.find(7) << endl;

	return 0;
}