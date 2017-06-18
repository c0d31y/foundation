#ifndef __GRAPH_DIGRAPH_H__
#define __GRAPH_DIGRAPH_H__

#include <iostream>
#include <string>

#include "bag.h"

namespace algs4 {

class Digraph {

 public:
	
	explicit Digraph(int v);
	explicit Digraph(const std::string& fpath);
	~Digraph();

	int V() const { return V_; }
	int E() const { return E_; }

	void addEdge(int v, int w);
	const Bag<int>& adj(int v) const;

 private:
	int V_;
	int E_;
	Bag<int> *adj_;
};

std::ostream& operator << (std::ostream& os, const Digraph& G);

}

#endif
