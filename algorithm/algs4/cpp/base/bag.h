#ifndef __BASE_BAG_H__
#define __BASE_BAG_H__

#include <iostream>

namespace algs4 {

template <typename T>
class BagIterator;

template <typename T>
class Bag;

template <typename T>
class Bag {

	struct Node;

	template <typename U>
	friend class BagIterator; 
	
 public:

	typedef BagIterator<T> iterator;

	Bag(): first(nullptr), n(0) { }

	~Bag() {
		for (Node *tmp = first; first; tmp = first) {
			first = first->next;
			delete tmp;
		}
	}

	bool empty() const { 
		return first == nullptr;
	} 

	int size() const { 
		return n;
	}

	void add(T item) {
		Node *tmp = first;
		first = new Node(item);
		first->next = tmp;
		++n;
	}

	iterator begin() const {
		return iterator(first);
	}

	iterator end() const {
		return iterator(nullptr);
	}

 private:
	
	Node *first;
	int n;
};

template <typename T>
struct Bag<T>::Node {
	Node *next;
	T item;
	Node(T i): next(nullptr), item(i) { }
};
	
template <typename T>
class BagIterator {

 public:

	BagIterator(typename Bag<T>::Node *first): cur(first) { }
	
	bool operator == (const BagIterator<T>& that) const {
		return cur == that.cur;
	}
	
  bool operator != (const BagIterator<T>& that) const {
		return !(*this == that);
	}	
	
	BagIterator<T>& operator ++ () {
		cur = cur->next;
		return *this;
	}

	BagIterator<T> operator ++ (int i) {
		typename Bag<T>::Node *tmp = cur;
		cur = cur->next;
		return *tmp;
	} 

	T& operator * () { return cur->item; }
	const T& operator * () const { return cur->item; }

 private:
	typename Bag<T>::Node *cur;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Bag<T>&  bag) {
	for (const auto& item : bag) os << item << " ";
	return os;
} 

}

#endif
