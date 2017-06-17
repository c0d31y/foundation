#include <iostream>
#include <string>

#include "bag.h"

int main(int argc, char *argv[]) {

	algs4::Bag<std::string> bag;
	std::string item;

	while (std::cin >> item) 
		bag.add(item);

	std::cout << bag 
						<< " (" << bag.size() << " items in bag)" 
						<< std::endl;
	return 0;
}
