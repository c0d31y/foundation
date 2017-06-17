#include <iostream>
#include <string>

#include "stack.h"

int main(int argc, char *argv[]) {
	
	algs4::Stack<std::string> stk;
	std::string item;

	while (std::cin >> item) {
		if (item == "-") std::cout << stk.pop() << " ";
		else 					   stk.push(item);
	}

	std::cout << " (" << stk.size() << " items left on stack)"
					  << std::endl;
	return 0;
}
