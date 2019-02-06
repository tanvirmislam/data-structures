#ifndef LIST_INCLUDE
#define LIST_INCLUDE

#include "node.h"

class List {
private:
	Node *listHead;

public:
	List();
	~List();

	void insert(int data);
	void append(int data);
	
	void reverseList();

	int  removeFromFront();
	int  removeFromBack();
	void deleteList();
	
	void printList();
};

#endif