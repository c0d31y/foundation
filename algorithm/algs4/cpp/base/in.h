#include <iostream>
#include <string>

#include "array.h"

namespace algs4 {

class In {
	
 public:

	In(std::istream& i): in(i) { }
	
  Array<std::string> readAllStrings();

 private:

	std::istream& in;
};

}
