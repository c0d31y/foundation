#include <iostream>

#include "graphs.h"

int main(int argc, char *argv[]) {
	algs4::Digraph G(argv[1]);
	std::cout << G << std::endl;
	return 0;
}
