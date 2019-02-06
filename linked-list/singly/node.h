#ifndef NODE_INCLUDE
#define NODE_INCLUDE

class Node {
private:
	int data;
	Node *nextNode;

public:
	Node(int d);
	void setNext(Node *node);
	Node* getNext();
	int getData();
};


#endif