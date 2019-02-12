#ifndef __UNION_FIND__
#define __UNION_FIND__

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <utility>

class Node {
public:
	int data;
	Node* parent;
	int rank;

	Node(int n) : data(n), parent(nullptr), rank(0) {}
};


class UnionFind {
public:	
	std::unordered_map<int, Node*> nodeMap;

	UnionFind() {}

	~UnionFind() {
		std::unordered_map<int, Node*>::const_iterator it;

		for (it = nodeMap.begin(); it != nodeMap.end(); ++it) {
			std::pair<int, Node*> current = *it;
			delete current.second;
		}
	}

	void makeSet(int val) {
		Node* newNode = new Node(val);
		newNode->parent = newNode;		// Self-pointing
		nodeMap.insert(std::make_pair(val, newNode));
	}

	// Find function
	// Returns parent
	// Path compression implemented
	int find(int val) {
		if (nodeMap.find(val) != nodeMap.end()) {
			return find(nodeMap[val])->data;
		}
		else {
			std::cout << "find error: value doesn't exist" << std::endl;
			return -1;
		}
	}

	Node* find(Node*& n) {
		if (n->parent != n) {
			// Path compression
			n->parent = find(n->parent);
		}

		return n->parent;
	}

	void performUnion(int x, int y) {
		if (nodeMap.find(x) == nodeMap.end() || nodeMap.find(y) == nodeMap.end()) {
			std::cout << "union error: value doesn't exist" << std::endl;
		}

		Node* node1 = nodeMap[x];
		Node* node2 = nodeMap[y];

		Node* parent1 = find(node1);
		Node* parent2 = find(node2);

		// If they're part of the same set, nothing to union
		if (parent1 == parent2) {
			return;
		}

		// They are not in the same set
		// Whichever has the higher ranked parent, that becomes the parent of the new set
		if (parent1->rank >= parent2->rank) {
			// Increment rank only if both ranks are the same
			if (parent1->rank == parent2->rank) {
				parent1->rank++;
			}

			// Set parent1 as parent2's parent
			parent2->parent = parent1;
		}
		else {
			// Set parent2 as parent1's parent
			parent1->parent = parent2;
		}
	}
};

#endif