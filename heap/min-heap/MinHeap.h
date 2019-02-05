#ifndef __MIN_HEAP__
#define __MIN_HEAP__

#include <iostream>
#include <algorithm>
#include <climits>

class MinHeap {
	int* heapArr;
	int  CAPACITY;
	int  size;

	void swap(int i, int j) {
		int temp = heapArr[i];
		heapArr[i] = heapArr[j];
		heapArr[j] = temp;
	}

	int getParentIndex(int i) { 
		if (i == 0) {
			return -1;
		}
		return (i-1)/2;
	}

	int getLeftChildIndex(int i) {
		int childIndex = (2*i) + 1;
		if (childIndex >= size) {
			return -1;
		}
		return childIndex;
	}

	int getRightChildIndex(int i) {
		int childIndex = (2*i) + 2;
		if (childIndex >= size) {
			return -1;
		}
		return childIndex;
	}

	bool hasParent(int i)		{ return getParentIndex(i) 		!= -1; }
	bool hasLeftChild(int i)	{ return getLeftChildIndex(i) 	!= -1; }
	bool hasRightChild(int i)	{ return getRightChildIndex(i)	!= -1; }

	int getParentVal(int i)		{ return heapArr[getParentIndex(i)]; 		}
	int getLeftChildVal(int i) 	{ return heapArr[getLeftChildIndex(i)]; 	}
	int getRightChildVal(int i)	{ return heapArr[getRightChildIndex(i)];	}

	void resize() {
		int NEW_CAPACITY = CAPACITY * 2;
		int* newHeapArr  = new int[NEW_CAPACITY];

		std::copy(heapArr, heapArr+size, newHeapArr);

		CAPACITY = NEW_CAPACITY;
		delete[] heapArr;
		heapArr = newHeapArr;
	}

	void upheap() {
		int index = size - 1;
		while (hasParent(index) && getParentVal(index) > heapArr[index]) {
			swap(index, getParentIndex(index));
			index = getParentIndex(index);
		}
	}

	void downheap() {
		int index = 0;
		while (hasLeftChild(index)) {
			// Smaller of left - right child
			int smallerChildIndex = getLeftChildIndex(index);
			if (hasRightChild(index) && getRightChildVal(index) < getLeftChildVal(index)) {
				smallerChildIndex = getRightChildIndex(index);
			}

			// downheap
			if (heapArr[index] < heapArr[smallerChildIndex]) {
				break;
			}
			else {
				swap(index, smallerChildIndex);
			}

			index = smallerChildIndex;
		}
	}

public:
	MinHeap(int cap) : CAPACITY(cap), size(0), heapArr(new int[CAPACITY]) {}

	~MinHeap() { delete[] heapArr; }

	void insert(int val) {
		if (size == CAPACITY) {
			resize();
		}

		// Add the new key at the very end
		heapArr[size] = val;
		size++;

		upheap();
	}

	int peek() {
		if (size == 0) {
			std::cout << "error: heap is empty" << std::endl;
			return INT_MAX;
		}
		return heapArr[0];
	}

	int extractMin() {
		if (size == 0) {
			std::cout << "error: heap is empty" << std::endl;
			return INT_MAX;
		}

		int minVal = heapArr[0];
		heapArr[0] = heapArr[size-1];
		size--;

		downheap();

		return minVal;
	}

	std::string toString() const {
		std::string str = "";
		if (size != 0) {
			str += "|";
			for (int i = 0; i < size; i++) {
				str += " " + std::to_string(heapArr[i]) + " |";
			}
		}
		return str;
	}
};

#endif