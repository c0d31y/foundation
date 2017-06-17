#include <iostream>
#include <string>

#include "in.h"
#include "indexminpq.h"

int main(int argc, char *argv[]) {
	
	algs4::In in(std::cin);
	auto a = in.readAllStrings();

	int n = a.size();
	algs4::IndexMinPQ<std::string> pq(n);
	for (int i = 0; i < n; ++i) {
		if (a[i] == "-") std::cout << a[pq.delmin()] << " ";
		else 						 pq.insert(i, a[i]);
	}
	std::cout << " (" << pq.size() << " left on index heap)" << std::endl;
	
	return 0;
}

	
