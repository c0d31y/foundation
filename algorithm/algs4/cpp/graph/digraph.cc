#include <iostream>
#include <fstream>
#include <string>

#include "bag.h"
#include "digraph.h"

namespace algs4 {

Digraph::Digraph(int v): V_(v), E_(0) { adj_ = new Bag<int>[v]; }	

Digraph::Digraph(const std::string& fpath) {

	int v, w, edges;
	std::ifstream fin(fpath);
	fin >> V_ >> edges;

	adj_ = new Bag<int>[V_];
	for (int e = 0; e < edges; ++e) {
		fin >> v >> w;
		addEdge(v, w);
	}
}

Digraph::~Digraph() { delete [] adj_; }

void Digraph::addEdge(int v, int w) {
	adj_[v].add(w);
	++E_;
}

const Bag<int>& Digraph::adj(int v) const { return adj_[v]; }
	
std::ostream& operator << (std::ostream& os, const Digraph& G) {

	os << G.V() << " vertices, " << G.E() << " edges" << std::endl;
	for (int v = 0; v < G.V(); ++v) {
		os << v << ": ";
		for (const auto& w : G.adj(v))
			os << w << " ";
		os << std::endl;
	}
	return os;
}

}
	
	
	
