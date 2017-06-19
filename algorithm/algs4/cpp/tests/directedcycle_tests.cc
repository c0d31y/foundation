#include <iostream>

#include "graphs.h"

int main(int argc, char *argv[]) {

	algs4::Digraph G(argv[1]);
	algs4::DirectedCycle finder(G);

	if (finder.hasCycle()) {
		std::cout << "Directed cycle: ";
		for (const auto& w : finder.cycle()) std::cout << w << " ";
		std::cout << std::endl;
	} else {
		std::cout << "No directed cycle" << std::endl;
	}
	return 0;
}

