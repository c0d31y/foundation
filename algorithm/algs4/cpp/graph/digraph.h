#ifndef __GRAPH_DIGRAPH_H__
#define __GRAPH_DIGRAPH_H__

#include <iostream>
#include <string>

#include "bag.h"
#include "stack.h"
#include "queue.h"

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
	Digraph reverse() const; 

 private:
	int V_;
	int E_;
	Bag<int> *adj_;
};

std::ostream& operator << (std::ostream& os, const Digraph& G);

class DirectedDFS {
	
 public:
	
	DirectedDFS(const Digraph& G, int s);
	DirectedDFS(const Digraph& G, const Bag<int>& sources);
	~DirectedDFS();

  bool hasPathTo(int v) const { return marked[v]; }	

 private:

	bool *marked;	
  void dfs(const Digraph& G, int v);	
};

class DirectedCycle {

 public:

	DirectedCycle(const Digraph& G);
	~DirectedCycle();

  bool hasCycle() const { return cycle_.size() != 0; }
	const Stack<int>& cycle() const { return cycle_; }

 private:

  bool *marked;
	bool *onStack;
	int  *edgeTo;
	Stack<int> cycle_;
	void dfs(const Digraph& G, int v); 
};

class DepthFirstOrder {
 
 public:

	DepthFirstOrder(const Digraph& G);
	~DepthFirstOrder();

	const Queue<int>& pre() const { return pre_; }
	const Queue<int>& post() const { return post_; }
	const Stack<int>& reversePost() const { return reversePost_; } 

 private:

	Queue<int> pre_;
	Queue<int> post_;
	Stack<int> reversePost_;
	
	bool *marked;
	void dfs(const Digraph& G, int v);
};

}
#endif
