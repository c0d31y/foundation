#include <iostream>
#include <string>

#include "graphs.h"

int main(int argc, char *argv[]) {
	
	algs4::Digraph G(argv[1]);

	algs4::Bag<int> sources;
	for (int i = 2; i < argc; ++i) { 
		int s = std::stoi(argv[i]);
		sources.add(s);
	}

	algs4::DirectedDFS dfs(G, sources);
	for (int v = 0; v < G.V(); ++v)
		if (dfs.hasPathTo(v)) std::cout << v << " ";
	std::cout << std::endl;

	return 0;
}
	
	
