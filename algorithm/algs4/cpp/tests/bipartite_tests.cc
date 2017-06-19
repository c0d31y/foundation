#include <iostream>

#include "graph.h"

int main(int argc, char *argv[]) {
	algs4::Graph G(argv[1]);
	algs4::Bipartite checker(G);
	if (checker.isBipartite()) std::cout << "The graph is bipartite";
	else											 std::cout << "The graph is not bipartite";
	std::cout << std::endl;
	return 0;
}
