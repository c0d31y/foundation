#include <iostream>
#include <string>

#include "in.h"
#include "array.h"
#include "queue.h"

int main(int argc, char *argv[]) {
  
  algs4::In in(std::cin);	
	auto a = in.readAllStrings();
	std::cout << a << " (" << a.size() << " items in array)" 
					  << std::endl;
	return 0;

}
