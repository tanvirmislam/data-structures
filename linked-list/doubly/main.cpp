#include <iostream>
#include "DoublyLinkedList.h"

int main(int argc, char* argv[]) {
	DoublyLinkedList<int> *dll1 = new DoublyLinkedList<int>();
	dll1->addToBack(1);
	dll1->addToBack(2);
	dll1->printList();
	dll1->addToBack(3);
	dll1->addToBack(4);
	dll1->printList();
	dll1->addToBack(5);
	dll1->printList();

	dll1->deleteFromBack();
	dll1->deleteFromBack();
	dll1->printList();

	dll1->deleteList();	
	delete dll1;

	return 0;
}