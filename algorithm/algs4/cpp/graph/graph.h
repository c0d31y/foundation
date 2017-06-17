#ifndef __GRAPH_GRAPH_H__
#define __GRAPH_GRAPH_H__

#include <iostream>

#include "bag.h"

namespace algs4 {

class Graph {

 public:

	Graph(int v);
	Graph(std::string fpath);
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

}
	

#endif

