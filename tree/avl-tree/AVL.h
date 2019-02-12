#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <iostream>
#include <utility>
#include <queue>

class TreeNode {
public:
	int value;
	TreeNode* left;
	TreeNode* right;
	int height;

	TreeNode(int n) : value(n), left(nullptr), right(nullptr), height(1) {}
};

class AvlTree {
	TreeNode* root;

public:
	AvlTree() : root(nullptr) {}

	// Get height of the tree starting from a node
	int getHeight(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}

	// Get balance factor of a given node
	// Balance factor = leftHeight - rightHeight
	int getBalanceFactor(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return (getHeight(node->left) - getHeight(node->right));
	}


	// Left rotation
	// Rotates left on the given pivot, returns new root
	TreeNode* leftRotate(TreeNode** pivot) {
		if (*pivot == nullptr || (*pivot)->right == nullptr) {
			std::cout << "left rotation error: nullptr" << std::endl;
			return nullptr;
		}

		std::cout << "left rotating at pivot " << (*pivot)->value << std::endl;

		TreeNode* r  = (*pivot)->right;
		TreeNode* rl = r->left;

		// Rotate
		r->left         = *pivot;
		(*pivot)->right = rl;
	
		// Update
		(*pivot)->height = std::max(getHeight((*pivot)->left), getHeight((*pivot)->right)) + 1;
		r->height        = std::max(getHeight(r->left),        getHeight(r->right))        + 1;
	
		// new root is r
		return r;
	}

	// Right rotation
	// Rotates right on the given pivot, returns new root
	TreeNode* rightRotate(TreeNode** pivot) {
		if (*pivot == nullptr || (*pivot)->left == nullptr) {
			std::cout << "right rotation error: nullptr" << std::endl;
			return nullptr;
		}

		std::cout << "right rotating at pivot " << (*pivot)->value << std::endl;

		TreeNode* l  = (*pivot)->left;
		TreeNode* lr = l->right;

		// Rotate
		l->right       = *pivot;
		(*pivot)->left = lr; 
	
		// Update
		(*pivot)->height = std::max(getHeight((*pivot)->left), getHeight((*pivot)->right)) + 1;
		l->height        = std::max(getHeight(l->left),        getHeight(l->right))        + 1;
	
		// new root is l
		return l;
	}


	// Insertion
	// Four different cases of rotation:
	// 1. Left-Left
	// 2. Left-Right
	// 3. Right-Left
	// 4. Right-Right
	TreeNode* insert(TreeNode** node, int val) {
		//std::cout << "inserting " << val << std::endl;
		// First insert the value as if it was being inserted in a BST
		if (*node == nullptr) {
			return (new TreeNode(val));
		}

		if (val < (*node)->value) {
			(*node)->left = insert(&((*node)->left), val);
		}
		else if (val > (*node)->value) {
			(*node)->right = insert(&((*node)->right), val);
		}
		else {
			std::cout << "insertion error: value already exists" << std::endl;
			return nullptr;
		}

		// Popping out of the recursion
		// Keep updating the heights of the parent nodes
		(*node)->height = std::max(getHeight((*node)->left), getHeight((*node)->right)) + 1;
		
		// Also get the balance factor
		int balanceFactor = getBalanceFactor(*node);
		std::cout << "balance factor of " << (*node)->value << " is " << balanceFactor << std::endl;

		// If the balanceFactor indicates that the current node is unbalanced, 
		// balance the tree with the current node being the pivot

		// Case 1: Left-Left, rotate right at the pivot
		if (balanceFactor > 1 && ((*node)->left) != nullptr && val < ((*node)->left)->value) {
			std::cout << "Case 1" << std::endl;
			return rightRotate(&(*node));
		}
		
		// Case 2: Right-Right, rotate left at the pivot
		if (balanceFactor < -1 && ((*node)->right) != nullptr && val > ((*node)->right)->value) {
			std::cout << "Case 2" << std::endl;
			return leftRotate(&(*node));
		}
		
		// Case 3: Left-Right, needs 2 rotations
		if (balanceFactor > 1 && ((*node)->left) != nullptr && val > ((*node)->left)->value) {
			std::cout << "Case 3" << std::endl;
			(*node)->left = leftRotate(&(*node)->left);
			return rightRotate(&(*node));
		}

		// Case 4: Right-Left, needs 2 rotations
		if (balanceFactor < -1 && ((*node)->right) != nullptr && val < ((*node)->right)->value) {
			std::cout << "Case 4" << std::endl;
			(*node)->right = rightRotate(&(*node)->right);
			return leftRotate(&(*node));
		}

		return (*node);
	}

	void insert(int val) {
		root = insert(&root, val);
	}

	void printLevelOrder() {
		std::cout << "Level Order Traversal:";

		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* visit = q.front();
			q.pop();

			if (visit == nullptr) {
				//std::cout << " null";
			}
			else {
				std::cout << " " << visit->value;
				q.push(visit->left);
				q.push(visit->right);
			}
		}

		std::cout << std::endl;
	}
};

#endif