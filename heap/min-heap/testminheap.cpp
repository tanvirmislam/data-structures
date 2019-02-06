#include "MinHeap.h"

#include <iostream>

std::ostream& operator<< (std::ostream& out, const MinHeap& minh) {
	out << minh.toString();
	return out;
}

int main() {
	MinHeap minh(10);

	minh.insert(5);
	minh.insert(-2);
	minh.insert(6);
	minh.insert(4);
	minh.insert(10);
	minh.insert(8);
	minh.insert(-8);
	minh.insert(-8);
	minh.insert(-8);
	minh.insert(9);

	std::cout << "extracting: " << minh.extractMin() << std::endl;
	std::cout << "extracting: " << minh.extractMin() << std::endl;

	std::cout << minh << std::endl;

	return 0;
}