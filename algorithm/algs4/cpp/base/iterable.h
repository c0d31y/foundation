#ifndef __BASE_ITERABLE_H__
#define __BASE_ITERABLE_H__

#include <iostream>

namespace algs4 {

class Iterator;
class Iterable;

template <typename T>
class Iterable {

 public:

	virtual ~Iterable() {}

	virtual Iterator<T> begin() const = 0;
	virtual Iterator<T> end()   const = 0;
};


template <typename T>
class Iterator {

 public:

	Iterator(T *p): ptr(p) {}
	virtual ~Iterator() {}

	virtual Iterator& operator ++() = 0;
	virtual Iterator  operator ++(int) = 0;

	virtual bool operator == (const Iterator& that) const = 0;
	virtual bool operator != (const Iterator& that) {
		return !(this == that);
	} 

	virtual const T& operator * () const = 0; 

 private:

	T *ptr;

};

template <typename T>
std::ostream& operator << (std::ostream& os, const Iterable<T>& it) {
	for (const auto& i : it) os << i << " ";
	return os;
}

}
	
#endif
