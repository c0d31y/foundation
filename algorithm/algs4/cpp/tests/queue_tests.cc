#include <iostream>
#include <string>

#include "queue.h"

int main(int argc, char *argv[]) {
	
	algs4::Queue<std::string> queue;
	std::string item;
	
	while (std::cin >> item) {
		if (item == "-") std::cout << queue.dequeue() << " ";
		else						 queue.enqueue(item);
	}

	std::cout << " (" << queue.size() << " items left on queue)"
						<< std::endl;
	return 0;
}
