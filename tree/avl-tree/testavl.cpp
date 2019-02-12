#include "AVL.h"
#include <iostream>

using namespace std;

int main() {
	AvlTree tree;

	tree.insert(10); 
	tree.insert(20); 
	tree.insert(30); 
	tree.insert(40); 
	tree.insert(50); 
	tree.insert(25);

	tree.printLevelOrder();
	
	return 0;
}