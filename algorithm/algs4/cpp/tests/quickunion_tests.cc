#include <iostream>

#include "unionfind.h"

#define HEAD 20

int main(int argc, char *argv[]) {

	int n, p, q;
	std::cin >> n;
	algs4::QuickUnion uf(n);

	int head = 0;
	while (std::cin >> p >> q) {
		if (!uf.same(p, q)) {
			if (++head < 20)
			  std::cout << p << " " << q << std::endl; 
			else if (head == HEAD) 
				std::cout << " ... ... " << std::endl;

			uf.connect(p, q);
		}
	}
	

	std::cout << uf.count() << " components." << std::endl;
}
