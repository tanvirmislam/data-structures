#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <unordered_set>

class Edge {
public:	
	int src;
	int dst;

	Edge(int s, int d) : src(s), dst(d) {}
};


class Graph {
public:	
	int totalVertices;
	int totalEdges;

	std::unordered_set<int> vertices;
	std::vector<Edge*> edges;

	Graph(int v, int e) : totalVertices(v), totalEdges(e) {}

	~Graph() {
		for (auto& e : edges) {
			delete e;
		}
	}

	void addEdge(int from, int to) {
		if (vertices.find(from) == vertices.end()) {
			vertices.insert(from);
		}

		if (vertices.find(to) == vertices.end()) {
			vertices.insert(to);
		}

		Edge* e = new Edge(from, to);
		edges.push_back(e);
	}
};

#endif