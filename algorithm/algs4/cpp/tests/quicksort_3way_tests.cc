#include <iostream>

#include "in.h"
#include "sort.h"

int main(int argc, char *argv[]) {
	
	algs4::In in(std::cin);
	auto a = in.readAllStrings();
	
	algs4::QuickSort::sort_3way(a);
	std::cout << a << std::endl;

	return 0;
}
