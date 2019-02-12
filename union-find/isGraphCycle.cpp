#include "UnionFind.h"
#include "Graph.h"

#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <utility>

using namespace std;

Graph* test1() {
	// Making graph:
	//  0 
    // |  \ 
    // |   \ 
    // 1----2

	int v = 3;
	int e = 3;
	Graph* gr = new Graph(v, e);

	gr->addEdge(0, 1);
	gr->addEdge(0, 2);
	gr->addEdge(1, 2);

	return gr;
}

Graph* test2() {
	// Making graph:
	//  0 
    // | 
    // |
    // 1----2

	int v = 3;
	int e = 3;
	Graph* gr = new Graph(v, e);

	gr->addEdge(0, 1);
	gr->addEdge(1, 2);

	return gr;
}


bool isCycle(Graph* gr) {
	UnionFind uf;

	// Convert graph to union find
	unordered_set<int>::const_iterator it;
	for (it = (gr->vertices).begin(); it != (gr->vertices).end(); ++it) {
		uf.makeSet(*it);
	}

	for (auto& edge : gr->edges) {
		int xRoot = uf.find(edge->src);
		int yRoot = uf.find(edge->dst);
	
		if (xRoot == yRoot) {
			return true;
		}

		uf.performUnion(xRoot, yRoot);
	}

	return false;
}

int main() {
	Graph* gr = test1();
	// Graph* gr = test2();

	cout << "Is graph cycled? " << (isCycle(gr) ? "YES" : "NO") << endl;
	
	delete gr;

	return 0;
}