#ifndef __GRAPH_GRAPH_H__
#define __GRAPH_GRAPH_H__

#include <iostream>

#include "bag.h"
#include "stack.h"

namespace algs4 {

class Graph {

 public:

	explicit Graph(int v);
	explicit Graph(const std::string& fpath);
	~Graph();

	int V() const { return V_; }
	int E() const { return E_; } 

	void addEdge(int v, int w);
	const Bag<int>& adj(int v) const;
	
 private:
	int V_;
	int E_;
	Bag<int> *adj_;
};

std::ostream& operator << (std::ostream& os, const Graph& G);

class DepthFirstPaths {
	
 public:
	
	DepthFirstPaths(const Graph& G, int s);
	~DepthFirstPaths();

	bool hasPathTo(int v) const;
	Stack<int> pathTo(int v) const;	

 private:

	int s_;
	bool *marked;
	int  *edgeTo;
	void dfs(const Graph& G, int v);
};

class BreadthFirstPaths {

 public:
	
	BreadthFirstPaths(const Graph& G, int s);
	~BreadthFirstPaths();

	bool hasPathTo(int v) const;
	const Stack<int> pathTo(int v) const;

 private:

	int s_;
	bool *marked;
	int *edgeTo;
	void bfs(const Graph& G, int v);
};

class Cycle {

 public:

	Cycle(const Graph& G);
	~Cycle();   

	bool hasCycle() const;
	const Stack<int>& cycle() const;
	
 private:
	
	bool *marked;
	int  *edgeTo;
	Stack<int> cycle_;
	void dfs(const Graph& G, int v, int u);
};

}
#endif
