#include <iostream>
#include "list.h"

using namespace std;

int main(int argc, char* argv[]) {
	List *l1 = new List();
	
	l1->append(1);				// 1
	l1->append(2);				// 1 2
	l1->append(3);				// 1 2 3
	l1->append(4);				// 1 2 3 4
	l1->append(5);				// 1 2 3 4 5
	
	l1->insert(0);				// 0 1 2 3 4 5
	l1->insert(-1);				// -1 0 1 2 3 4 5
	l1->insert(-2);				// -2 -1 0 1 2 3 4 5
	
	l1->removeFromBack();		// -2 -1 0 1 2 3 4
	l1->removeFromFront();		// -1 0 1 2 3 4
	l1->removeFromBack();		// -1 0 1 2 3

	l1->reverseList();			// 3 2 0 -1
	l1->reverseList();			// -1 0 2 3
	l1->reverseList();			// 3 2 0 -1
	
	l1->printList();

	l1->deleteList();
	delete(l1);

	return 0;
}