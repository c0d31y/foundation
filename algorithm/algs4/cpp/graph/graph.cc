#include <iostream>
#include <fstream>
#include <string>

#include "graph.h"

namespace algs4 {

Graph::Graph(int v): V_(v), E_(0) { adj_ = new Bag<int>[v]; }

Graph::Graph(std::string fpath): V_(0), E_(0) {

  int v, w, edges;	
	std::ifstream fin(fpath);
	fin >> V_ >> edges;

	adj_ = new Bag<int>[V_];
	for (int e = 0; e < edges; ++e) {
		fin >> v >> w; 
		addEdge(v, w);
	}
}
	
Graph::~Graph() { delete[] adj_; }

void Graph::addEdge(int v, int w) {
	adj_[v].add(w);
	adj_[w].add(v);
	++E_;
}

const Bag<int>& Graph::adj(int v) const { return adj_[v]; }
	
std::ostream& operator << (std::ostream& os, const Graph& G) {

	os << G.V() << " vertices, " << G.E() << " edges" << std::endl;
	for (int v = 0; v < G.V(); ++v) {
		os << v << ": ";
		for (const auto& w : G.adj(v)) {
			os << w << " ";
		}
		os << std::endl;
	}
	return os;
}

}
