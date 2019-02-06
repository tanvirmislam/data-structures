#include "node.h"

Node::Node(int d) : data(d), nextNode(nullptr) {}

void Node::setNext(Node* next) { 
	nextNode = next;
}

Node* Node::getNext() {
	return nextNode;
}

int Node::getData() {
	return data;
}