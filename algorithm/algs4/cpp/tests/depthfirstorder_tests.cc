#include <iostream>

#include "graphs.h"

int main(int argc, char *argv[]) {
	algs4::Digraph G(argv[1]);
	algs4::DepthFirstOrder dfs(G);

	std::cout << "preorder: ";
	for (const auto& w : dfs.pre()) std::cout << w << " ";
	std::cout << std::endl;

	std::cout << "postorder: ";
	for (const auto& w : dfs.post()) std::cout << w << " ";
	std::cout << std::endl;

	std::cout << "reversePost: ";
	for (const auto& w : dfs.reversePost()) std::cout << w << " ";
	std::cout << std::endl;
	return 0;
}
