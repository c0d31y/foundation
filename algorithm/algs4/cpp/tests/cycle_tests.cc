#include <iostream>

#include "graph.h"

int main(int argc, char *argv[]) {

	algs4::Graph G(argv[1]); 
	algs4::Cycle finder(G);
	
	if (finder.hasCycle()) {
		std::cout << "Cycle: ";
		for (const auto& v : finder.cycle()) std::cout << v << " ";
		std::cout << std::endl;
	} else {
		std::cout << "No cycle" << std::endl;
	}

	return 0;
}
