#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__

#include <iostream>

template <class T>
class Node {
public:
	T data;
	Node *next;
	Node *prev;

	Node() : next(nullptr), prev(nullptr) {}
	Node(const T& val, Node *n, Node *p) : data(val), next(n), prev(p) {}
};

template <class T>
class DoublyLinkedList {
public:
	Node<T> *head;
	Node<T> *tail;

	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

 	~DoublyLinkedList() {
 		deleteList();
 	}

	void addToBack(const T&);
	T deleteFromBack();
	void printList();
	void deleteList();
};

template <class T>
void DoublyLinkedList<T>::addToBack(const T& dat) {
	if (tail != nullptr) {
		Node<T> *newTail = new Node<T>(dat, nullptr, tail);
		tail->next = newTail;
		tail = newTail;
	}
	else {
		head = new Node<T>(dat, nullptr, nullptr);
		tail = head;
	}
}

template <class T>
T DoublyLinkedList<T>::deleteFromBack() {
	if (tail == nullptr) {
		return 0;
	}
		
	T deletedData = tail->data;
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
}

template <class T>
void DoublyLinkedList<T>::printList() {
	Node<T> **cursor = new Node<T>*();
	*cursor = head;
	
	while ((*cursor) != nullptr) {
		std::cout << (*cursor)->data << " ";
		cursor = &((*cursor)->next);
	}
	std::cout << std::endl;

	delete cursor;
}

template <class T>
void DoublyLinkedList<T>::deleteList() {
	while (tail != head) {
		tail = tail->prev;
		delete tail->next;
	}
	delete tail;
	delete head;
}

#endif