#include "list.h"
#include "node.h"
#include <stdio.h>
#include <iostream>

List::List() : listHead(nullptr) {}

List::~List() { deleteList(); } 

void List::insert(int data) {
	Node *newNode = new Node(data);

	if (listHead == nullptr) {
		listHead = newNode;
	}
	else {
		newNode->setNext(listHead);
		listHead = newNode;
	}
}

void List::append(int data) {
	Node *newNode = new Node(data);

	if (listHead == nullptr) {
		listHead = newNode;
	}
	else {
		Node *temp = listHead;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(newNode);
	}
}

void List::reverseList() {
	Node* prev    = nullptr;
	Node* current = listHead;
	
	while (current != nullptr) {
		Node* next = current->getNext();

		current->setNext(prev);
		prev = current;
		current = next;

		next = nullptr;
		delete next;
	}

	listHead = prev;
}

int List::removeFromFront() {
	if (listHead == nullptr) {
		return -1;
	}

	Node *temp = listHead;
	int removedData = temp->getData();
	listHead = listHead->getNext();
	delete temp;
	return removedData;
}

int List::removeFromBack() {
	if (listHead == nullptr) {
		return -1;
	}
	else if (listHead->getNext() == nullptr) {
		int removedData = listHead->getData();
		listHead = nullptr;
		return removedData;
	}

	Node *prev     = listHead;
	Node *lastNode = listHead->getNext();
	

	while (lastNode->getNext() != nullptr) {
		prev = lastNode;
		lastNode = lastNode->getNext();
	}

	int removedData = lastNode->getData();
	delete(lastNode);
	prev->setNext(nullptr);
	return removedData;
}

void List::deleteList() {
	while (listHead != nullptr) {
		Node *temp = listHead;
		listHead = listHead->getNext();
		delete temp;
	}
	delete listHead;
}

void List::printList() {
	Node *currentNode = listHead;
	while (currentNode != nullptr) {
		printf("%d ", currentNode->getData());
		currentNode = currentNode->getNext();
	}
}