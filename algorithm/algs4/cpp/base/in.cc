#include <iostream>
#include <string>

#include "in.h"
#include "queue.h"
#include "array.h"

namespace algs4 {

Array<std::string> In::readAllStrings() {

	Queue<std::string> q;
	std::string item;
	while (std::cin >> item) q.enqueue(item);

	Array<std::string> a(q.size());
	for (int i = 0; i < a.size(); ++i) a[i] = q.dequeue();
	return a;
}

}
