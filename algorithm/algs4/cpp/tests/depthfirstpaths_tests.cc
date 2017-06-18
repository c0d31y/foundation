#include <iostream>
#include <string>

#include "graph.h"

int main(int argc, char *argv[]) {
	algs4::Graph G(argv[1]);
	int s = std::stoi(argv[2]);

	algs4::DepthFirstPaths path(G, s);
	for (int v = 0; v < G.V(); ++v) {
		std::cout << s << " to " << v << ": ";
		if (path.hasPathTo(v)) {
			for (const auto& w : path.pathTo(v)) {
				if (w == s) std::cout << w;
				else 				std::cout << "-" << w; 
			}
		} else {
			std::cout << "no path";
		}
		std::cout << std::endl;
	}

	return 0;
}
	
