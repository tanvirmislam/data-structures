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

	void setValue(const T& val)       { data       = val ; }
	void setParent(Node<T>* node)     { parent     = node; }
	void setLeftChild(Node<T>* node)  { leftChild  = node; }
	void setRightChild(Node<T>* node) { rightChild = node; }
	void setNull()					  { parent = nullptr; leftChild = nullptr; rightChild = nullptr; }

	T        getValue()       { return data      ; }
	Node<T>* getParent()      { return parent    ; }
	Node<T>* getLeftChild ()  { return leftChild ; }
	Node<T>* getRightChild () { return rightChild; }

	bool hasLeftChild()  { return (leftChild  != nullptr); }
	bool hasRightChild() { return (rightChild != nullptr); }
	bool hasChild()      { return (hasRightChild() || hasLeftChild()); }

	void swapChild() {
		Node<T>* temp = leftChild;
		leftChild     = rightChild;
		rightChild    = temp;
	}

	void deleteChild() {
		delete leftChild;
		delete rightChild;
	}

	void deleteNode() {
		delete parent;
		delete leftChild;
		delete rightChild;
	}
};

#endif