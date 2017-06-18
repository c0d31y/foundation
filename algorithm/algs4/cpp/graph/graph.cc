#include <iostream>
#include <fstream>
#include <string>

#include "queue.h"
#include "graph.h"

namespace algs4 {

Graph::Graph(int v): V_(v), E_(0) { adj_ = new Bag<int>[v]; }

Graph::Graph(const std::string& fpath): V_(0), E_(0) {

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

DepthFirstPaths::DepthFirstPaths(const Graph& G, int s): s_(s) {
	marked = new bool[G.V()]();
	edgeTo = new int[G.V()]();
	dfs(G, s);
}
  
DepthFirstPaths::~DepthFirstPaths() {
	delete [] marked;
	delete [] edgeTo;
}

bool DepthFirstPaths::hasPathTo(int v) const { return marked[v]; }

Stack<int> DepthFirstPaths::pathTo(int v) const {
	Stack<int> path;
	for (int x = v; x != s_; x = edgeTo[x])
		path.push(x);
	path.push(s_);
	return path;
}
	

void DepthFirstPaths::dfs(const Graph& G, int v) {
	marked[v] = true;
	for (const auto& w : G.adj(v)) {
		if (!marked[w]) {
			edgeTo[w] =v;
			dfs(G, w);
		}
	}
}

BreadthFirstPaths::BreadthFirstPaths(const Graph& G, int s): s_(s) {
	marked = new bool[G.V()]();
	edgeTo = new int[G.V()]();
	bfs(G, s);
}	

BreadthFirstPaths::~BreadthFirstPaths() {
	delete [] marked;
	delete [] edgeTo;
}

bool BreadthFirstPaths::hasPathTo(int v) const { return marked[v]; }

const Stack<int> BreadthFirstPaths::pathTo(int v) const {
	Stack<int> path;
	for (int x = v; x != s_; x = edgeTo[x]) 
		path.push(x);
	path.push(s_);
	return path;
}

void BreadthFirstPaths::bfs(const Graph& G, int s) {

	Queue<int> q;
	q.enqueue(s);
	marked[s] = true;

	while (!q.isEmpty()) {
		int v = q.dequeue();
		for (const auto& w : G.adj(v)) {
			if (!marked[w]) {
				edgeTo[w] =v;
				marked[w] =true;
				q.enqueue(w);
			}
		}
	}
}

Cycle::Cycle(const Graph& G) {
	marked = new bool[G.V()]();
	edgeTo = new int[G.V()]();

	for (int v = 0; v < G.V(); ++v) {
		if (!marked[v]) dfs(G, v, v);
	}
}

Cycle::~Cycle() {
	delete [] marked;
	delete [] edgeTo;
}

bool Cycle::hasCycle() const { return cycle_.size() != 0; }
const Stack<int>& Cycle::cycle() const { return cycle_; }

void Cycle::dfs(const Graph& G, int v, int u) {

	marked[v] = true;
	for (const auto& w : G.adj(v)) {
		if (hasCycle()) return;
		else if (!marked[w]) {
			edgeTo[w] = v;
			dfs(G, w, v);
		} else if (w != u) {
			for (int x = v; x != w; x = edgeTo[x])
				cycle_.push(x);
			cycle_.push(w);
			cycle_.push(v);
		}
	}
}

}
