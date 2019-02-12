#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node {
private:
	T data;
	Node<T>* parent;
	Node<T>* leftChild;
	Node<T>* rightChild;

public:
	Node(const T& val) : data(val), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
	
	~Node() {}

	void setValue(const T& val)		{ data = val ; }

	void setParent(Node<T>** node) { 
		if (node == nullptr) {
			parent = nullptr; 
		}
		else { 
			parent = *node; 
		}
	}

	void setLeftChild(Node<T>** node) { 
		if (node == nullptr) {
			leftChild = nullptr; 
		}
		else { 
			leftChild = *node; 
		}
	}

	void setRightChild(Node<T>** node) { 
		if (node == nullptr) {
			rightChild = nullptr; 
		}
		else { 
			rightChild = *node; 
		}
	}

	void setNul() { 
		parent = nullptr; 
		leftChild = nullptr; 
		rightChild = nullptr; 
	}

	T        getValue()       { return data      ; }
	Node<T>* getParent()      { return parent    ; }
	Node<T>* getLeftChild ()  { return leftChild ; }
	Node<T>* getRightChild () { return rightChild; }

	Node<T>** getParentRef()		{ return &parent; 		}
	Node<T>** getLeftChildRef()		{ return &leftChild; 	}
	Node<T>** getRightChildRef()	{ return &rightChild; 	}

	bool hasLeftChild()  { return (leftChild  != nullptr); }
	bool hasRightChild() { return (rightChild != nullptr); }
	bool hasChild()      { return (hasRightChild() || hasLeftChild()); }

	void swapChild() {
		Node<T>* temp = leftChild;
		leftChild     = rightChild;
		rightChild    = temp;
	}
};

#endif