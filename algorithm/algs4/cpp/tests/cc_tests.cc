#include <iostream>

#include "queue.h"
#include "graphs.h"

int main(int argc, char *argv[]) {
	
	algs4::Graph G(argv[1]);
	algs4::CC cc(G);
	algs4::Queue<int> *components = new algs4::Queue<int>[cc.count()];
	for (int v = 0; v < G.V(); ++v)
		components[cc.cid(v)].enqueue(v);

	for (int c = 0; c < cc.count(); ++c) {
		std::cout << c << ": ";
		for (const auto& v : components[c])
			std::cout << v << " ";
		std::cout << std::endl;
	}
	
	delete [] components;
	return 0;
}
				
