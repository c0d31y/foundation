#include <iostream>

#include "in.h"
#include "minpq.h"

int main(int argc, char *argv[]) {
	
	algs4::In in(std::cin);
	auto a = in.readAllStrings();

	algs4::MinPQ<std::string> pq(a.size());
	for (const auto& item : a) {
		if (item == "-") std::cout << pq.delmin() << " ";
		else 						 pq.insert(item);
	}
	std::cout << " (" << pq.size() << " left on heap)" << std::endl;
	
	return 0;
}
