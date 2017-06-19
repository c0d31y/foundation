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

DirectedDFS::DirectedDFS(const Digraph& G, int s) {
	marked = new bool[G.V()]();
	dfs(G, s);
}

DirectedDFS::DirectedDFS(const Digraph& G, const Bag<int>& sources) {
	marked = new bool[G.V()]();
	for (const auto& s : sources) dfs(G, s);
}

DirectedDFS::~DirectedDFS() { delete [] marked; }

void DirectedDFS::dfs(const Digraph& G, int v) {
	marked[v] = true;
	for (const auto& w : G.adj(v))
		if (!marked[w]) dfs(G, w);
}

DirectedCycle::DirectedCycle(const Digraph& G) {
	marked = new bool[G.V()]();
	onStack = new bool[G.V()]();
	edgeTo = new int[G.V()]();
	for (int v = 0; v < G.V(); ++v)
		if (!marked[v]) dfs(G, v);
}

DirectedCycle::~DirectedCycle() {
	delete [] marked;
	delete [] onStack;
	delete [] edgeTo;
}

void DirectedCycle::dfs(const Digraph& G, int v) {
	marked[v] = true;
	onStack[v] = true;
	for (const auto& w : G.adj(v)) {
		if (hasCycle()) return ;
		else if (!marked[w]) {
			edgeTo[w] = v;
			dfs(G, w);
		} else if (onStack[w]) {
			for (int x = v; x != w; x = edgeTo[x])
				cycle_.push(x);
			cycle_.push(w);
			cycle_.push(v);
		}
	}
	onStack[v] = false;
}

DepthFirstOrder::DepthFirstOrder(const Digraph& G) {
	marked = new bool[G.V()]();
	for (int v = 0; v < G.V(); ++v)
		if (!marked[v]) dfs(G, v);
}  

DepthFirstOrder::~DepthFirstOrder() { delete [] marked; }

void DepthFirstOrder::dfs(const Digraph& G, int v) {
	marked[v] = true;
	pre_.enqueue(v);
	for (const auto& w: G.adj(v)) {
		if (!marked[w]) dfs(G, w);
	}
	post_.enqueue(v);
	reversePost_.push(v);
}

}
