#ifndef __BASE_ARRAY_H__
#define __BASE_ARRAY_H__

#include <iostream>

namespace algs4 {

template <typename T>
class ArrayIterator;

template <typename T>
class Array;

template <typename T>
class Array {

	template <typename U>
	friend class ArrayIterator;

 public:

	typedef ArrayIterator<T> iterator;

	explicit Array(int c): a(nullptr), capacity(c) {
		a = new T[capacity];  
	}

	Array(Array<T>&& other) { 
		a = other.a; capacity = other.capacity; other.a = nullptr;
	}

	~Array() { delete[] a; }

	Array<T>& operator = (const Array<T>&& other) {
		if (this != &other) {
			delete[] a;
			a = other.a;
			capacity = other.capacity;
			other.a = nullptr;
		}
		return *this;
	}
		
	int size() { return capacity; } 

	T& operator [] (int i) { return *(a + i); }
	const T& operator [] (int i) const { return *(a + i); }

	iterator begin() const { return iterator(a); }
	iterator end()   const { return iterator(a + capacity); }

 private:
	
	T *a;
	int capacity;
};

template <typename T>
class ArrayIterator {

 public:

	ArrayIterator(T *c): cur(c) { }

	bool operator == (const ArrayIterator<T>& that) {
		return cur == that.cur;
	}

	bool operator != (const ArrayIterator<T>& that) {
		return !(*this == that);
	}

	ArrayIterator& operator ++ () { ++cur; return *this; }
	ArrayIterator operator ++ (int i) { T *tmp; ++cur; return *tmp; }

	T& operator * () { return *cur; }
	const T& operator * () const { return *cur; }

 private:

	T *cur;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Array<T>& a) {
	for (const auto& i : a) std::cout << i << " ";
	return os;
}

}

#endif
