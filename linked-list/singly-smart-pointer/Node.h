#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>
#include <memory>

template <class T>
struct Node
{
	T data;
	std::unique_ptr<Node<T>> nextNode;

	Node(const T& d) : data(d), nextNode() {}
	Node(const T& d, std::unique_ptr<Node<T>>&& next) : data(d), nextNode(std::move(next)) {}

	Node(T&& d) : data(std::move(d)), nextNode() {}

	~Node() { std::cout << "Node deleted" << std::endl; }


	//void setData(const T& d) { data = d; };
	//T getData() { return data; }

	void setNextNode(std::unique_ptr<Node<T>>&& up) { nextNode = std::move(up); };
};



#endif
