#include <iostream>
#include <queue>
#include <vector>
#include "BST.h"

using namespace std;

void test1() {
	/*
	Testing with the following tree:
	                                5
	                               /  \
	                              2    12
	                             /\    /  \
	                           -4 3   9    21
	                                   \  / \
	                                  10 19  25
	                                       \
	                                       20


	Inverted Tree:
	                                       5
	                                     /   \ 
	                                   12      2
	                                   / \    / \
	                                 21  9   3  -4
	                                 / \ 
	                                25  19
	                                    /
	                                   20                           

	*/

	BST<long> tree;
	tree.addValue(5);
	tree.addValue(2);
	tree.addValue(12);
	tree.addValue(-4);
	tree.addValue(3);
	tree.addValue(9);
	tree.addValue(21);
	tree.addValue(10);
	tree.addValue(19);
	tree.addValue(25);
	tree.addValue(20);

	tree.printBreadthFirst();
	tree.printInorder();
	tree.printPreorder();
	tree.printPostorder();

	//tree.invertTree();
	//tree.printBreadthFirst();

	// cout << "\nDeleting node...\n" << endl;
	// tree.deleteNode(-4);
	// tree.printBreadthFirst();


	tree.deleteTree();
}

int main(int argc, char* argv[]) {
	test1();
	return 0;
}

