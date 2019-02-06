#ifndef __BST_H__
#define __BST_H__

#include "node.h"
#include <iostream>
#include <queue>
#include <string>

//using namespace std;

template <class T>
class BST {
private:
	Node<T>* root;

	void 		addLeft(const T& val, Node<T>* node);
	void 		addRight(const T& val, Node<T>* node);
	void 		add(const T& val, Node<T>* node);
	
	Node<T>* 	find(const T& val, Node<T>* node);
	
	void 		visit(Node<T>* node);
	void 		inorder(Node<T>* node);
	void 		preorder(Node<T>* node);
	void 		postorder(Node<T>* node);
	
	void 		invertTree(Node<T>* node);
	
	Node<T>*	getMinValueNode(Node<T>* node); 

	void 		printTree(Node<T>* node, int currentDepth, int currentSpace, std::vector<std::string> container);
	
	void 		deleteTree(Node<T>* node);

public:
	BST() : root(nullptr) {}

	~BST() { deleteTree(root); }

	void 		addValue (const T& val);

	Node<T>*	find(const T& val);
	T 			findParentValue(const T& val);
	
	void 		invertTree();
	
	void 		printBreadthFirst();
	void 		printInorder();
	void 		printPreorder();
	void 		printPostorder();
	void 		guiPrintTree();
	
	void 		deleteNode(T val);
	void 		deleteTree();
};

template <class T>
void BST<T>::addLeft(const T& val, Node<T>* node) {
	std::cout << "adding left" << std::endl;
    if (node->getLeftChild() == nullptr) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setParent(node);
        node->setLeftChild(newNode);
    }
    else {
        std::cout<< "insert error: already has a left child\n" << std::endl;
    }
}

template <class T>
void BST<T>::addRight(const T& val, Node<T>* node) {
	std::cout << "adding right" << std::endl;
    if (node->getRightChild() == nullptr) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setParent(node);
        node->setRightChild(newNode);
    }
    else {
        std::cout<< "insert error: already has a right child\n" << std::endl;
    }
}

template <class T>
void BST<T>::add(const T& val, Node<T>* node) {
	// Add to left child if value < currentNode->value
	// Else, add to the right child
    if (val < node->getValue()) {
    	std::cout << "val < node->getValue()" << std::endl;
        if (node->hasLeftChild()) {
            add(val, node->getLeftChild());
        }
        else {
        	addLeft(val, node);
        }
    }
    else {
    	std::cout << "val >= node->getValue()" << std::endl;
        if (node->hasRightChild()) {
            add(val, node->getRightChild());
        }
        else {
            addRight(val, node);
        }
    }
}

template <class T>
void BST<T>::addValue (const T& val) {
    if (root == nullptr) {
    	std::cout << "adding root" << std::endl;
        root = new Node<T>(val);
    }
	else {
        add(val, root);
	}
}


template <class T>
Node<T>* BST<T>::find(const T& val, Node<T>* node) {
    if (node == nullptr) {
    	return nullptr;
    }

	if (val == node->getValue()) {
		return node;
	}
	
	if (val < node->getValue()) {
		return find(val, node->getLeftChild());
	} 
	else {
		return find(val, node->getRightChild());
	}
}

template <class T>
Node<T>* BST<T>::find(const T& val) {
	Node<T>* targetNode = find(val, root);
	return targetNode;
}


template <class T>
T BST<T>::findParentValue(const T& val) {
	Node<T>* targetNode = find(val, root);
	
	if (targetNode->getParent() == nullptr) {
		return targetNode->getValue();
	}
	else {
		return (targetNode->getParent())->getValue();
	}
}


template <class T>
void BST<T>::invertTree(Node<T>* node) {
	if (node == nullptr) {
		return;
	}
	
	// Recursively swap

	if (node->hasLeftChild()) {
		invertTree(node->getLeftChild());
	}
	if (node->hasRightChild()) {
		invertTree(node->getRightChild());
	}

	node->swapChild();
}

template <class T>
void BST<T>::invertTree() {
	if (root == nullptr) {
		return;
	}
	invertTree(root);
}


template <class T>
void BST<T>::visit(Node<T>* node) {
	std::cout << node->getValue() << "  ";
}

template <class T>
void BST<T>::inorder(Node<T>* node) {
	if (node != nullptr) {
		inorder(node->getLeftChild());
		visit(node);
		inorder(node->getRightChild());
	}
}

template <class T>
void BST<T>::preorder(Node<T>* node) {
	if (node != nullptr) {
		visit(node);
		preorder(node->getLeftChild());
		preorder(node->getRightChild());
	}
}

template <class T>
void BST<T>::postorder(Node<T>* node) {
	if (node != nullptr) {
		postorder(node->getLeftChild());
		postorder(node->getRightChild());
		visit(node);
	}
}

template <class T>
void BST<T>::printBreadthFirst() {
	if (root == nullptr) {
		return;
	}

	Node<T>* temp = root;
	std::queue<Node<T>*> level;
	level.push(temp);

	std::cout << "\nBreadth First Traversel: ";

	while (!level.empty()) {
		std::cout << (level.front())->getValue() << "  ";
		
		if ( (level.front())->hasLeftChild() ) {
			level.push( (level.front())->getLeftChild() );
		}
		if ( (level.front())->hasRightChild() ){
			level.push( (level.front())->getRightChild() );
		}
		
		level.pop();
	}

	std::cout << "\n" << std::endl;
}

template <class T>
void BST<T>::printInorder() {
	if (root == nullptr) {
		return;
	}

	std::cout << "\nInorder Traversel: ";
	inorder(root);
	std::cout << "\n" << std::endl;
}

template <class T>
void BST<T>::printPreorder() {
	if (root == nullptr) {
		return;
	}

	std::cout << "\nPreorder Traversel: ";
	preorder(root);
	std::cout << "\n" << std::endl;
}

template <class T>
void BST<T>::printPostorder() {
	if (root == nullptr) {
		return;
	}

	std::cout << "\nPostorder Traversel: ";
	postorder(root);
	std::cout << "\n" << std::endl;
}


template <class T> 
Node<T>* BST<T>::getMinValueNode(Node<T>* node) {
	if (node == nullptr) {
		return nullptr;
	}

	Node<T>* current = node;
	while (current->hasLeftChild()) {
		current = current->getLeftChild();
	}
	return current;
}

/*

3 Cases:
	- No  children	
	- One children
	- Two children

For a node that has more than 1 children:
- find a minimum value in the right subtree;
- replace value of the node to be removed with found minimum. Now, right subtree contains a duplicate!
- apply remove to the right subtree to remove a duplicate.

*/

// Needs correction
template <class T>
void BST<T>::deleteNode(T val) {
	if (root == nullptr) {
		return;
	}

	Node<T>* targetNode = find(val);
	if (targetNode == nullptr) { 
		return;
	}

	std::cout << "Found node to be deleted: " << targetNode->getValue() << std::endl;
	
	// No children
	if (!targetNode->hasChild()) {
		std::cout << "it has no children" << std::endl;  
		if (targetNode == root) {
			root = nullptr;
			return;
		}
		else {
			Node<T>* par = targetNode->getParent();

			if ( par->getLeftChild() == targetNode ) {
				std::cout << "LEFT" << std::endl; 
				par->setLeftChild(nullptr);
			}
			else {
				std::cout << "RIGHT" << std::endl; 
				par->setRightChild(nullptr);
			}
			
			// delete targetNode;
		}
	}
	// One children
	else if ( ((targetNode->hasLeftChild() == true)  && (targetNode->hasRightChild() == false)) || 
		      ((targetNode->hasLeftChild() == false) && (targetNode->hasRightChild() == true)) ) {
		std::cout << "it has 1 child" << std::endl;
		if (targetNode == root) {
			if (targetNode->hasLeftChild() == true) {
				root = targetNode->getLeftChild();
			}
			else {
				root = targetNode->getRightChild();
			}

			root->setParent(nullptr);
			targetNode->setNull();
		}
		else {
			Node<T>* par = targetNode->getParent();

			if (targetNode->hasLeftChild() == true) {
				Node<T>* leftChild = targetNode->getLeftChild();

				if (par->getLeftChild() == targetNode) {
					par->setLeftChild(leftChild);
				}
				else {
					par->setRightChild(leftChild);
				}

				leftChild->setParent(par);
			}
			else {
				Node<T>* rightChild = targetNode->getRightChild();

				if (par->getLeftChild() == targetNode) {
					par->setLeftChild(rightChild);
				}
				else {
					par->setRightChild(rightChild);
				}
			
				rightChild->setParent(par);
			}

			// delete targetNode;
		}
	}
	// Two children
	else {
		std::cout << "it has 2 children" << std::endl;
		Node<T>* swapWith = getMinValueNode(targetNode->getRightChild());
		std::cout << "swapping with: " << swapWith->getValue() << std::endl;
		
		targetNode->setValue(swapWith->getValue());
		
		if (swapWith->getParent() == targetNode) {
			targetNode->setRightChild(nullptr);
		}
		else {
			(swapWith->getParent())->setLeftChild(nullptr);
		}

		//delete swapWith;
	}
}


template <class T>
void BST<T>::printTree(Node<T>* node, int currentDepth, int currentSpace, std::vector<std::string> container) {
	for (int i = 0; i < currentSpace; i++) {
		std::cout << " ";	
	}
	std::cout << root->getValue() << std::endl;

	if (node->hasLeftChild()) {
		for (int i = 0; i < currentSpace-1; i++) {
			std::cout << " ";
		}
		std::cout << "/";
		printTree(node->getLeftChild(), currentDepth+1, currentSpace-3);
	}

	if (node->hasRightChild()) {
		for (int i = 0; i < currentSpace+3; i++) {
			std::cout << " ";
		}
		std::cout << "\\";
	}

}

template <class T>
void BST<T>::guiPrintTree() {
	int rootSpace = (4*5);
	printTree(root, 0, rootSpace);
}


template <class T>
void BST<T>::deleteTree(Node<T>* node) {
	if (node == nullptr) {
		return;
	}
	if (node->hasLeftChild()) {
		deleteTree(node->getLeftChild());
	}
	if (node->hasRightChild()) {
		deleteTree(node->getRightChild());
	}
	node->deleteNode();
}

template <class T>
void BST<T>::deleteTree() {
	if (root == nullptr) {
		return;
	}
	deleteTree(root);
}



#endif