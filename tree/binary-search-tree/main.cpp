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
	                                      / \
	                                     19  25
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
	tree.add(5);
	tree.add(2);
	tree.add(12);
	tree.add(-4);
	tree.add(3);
	tree.add(9);
	tree.add(21);
	tree.add(19);
	tree.add(25);
	tree.add(20);

	tree.printBreadthFirst();
	tree.printInorder();
	tree.printPreorder();
	tree.printPostorder();

	cout << "Is valid BST? " << (tree.validateTree() ? "YES" : "NO") << endl;

	cout << "\nDeleting node..." << endl;
	tree.deleteNode(19);
	tree.deleteNode(25);
	tree.deleteNode(5);
	tree.printBreadthFirst();

	cout << "Is valid BST? " << (tree.validateTree() ? "YES" : "NO") << endl;

	cout << "\nInverting tree..." << endl;
	tree.invertTree();
	tree.printBreadthFirst();

	cout << "Is valid BST? " << (tree.validateTree() ? "YES" : "NO") << endl;
}

int main(int argc, char* argv[]) {
	test1();
	return 0;
}

