#ifndef __BASE_STACK_H__
#define __BASE_STACK_H__

#include <iostream>

namespace algs4 {

template <typename T>
class StackIterator;

template <typename T>
class Stack;

template <typename T>
class Stack {

	struct Node;

	template <typename U>
	friend class StackIterator;

 public:

	typedef StackIterator<T> iterator;

	Stack(): first(nullptr), n(0) { }

	~Stack() {
		for (Node *tmp = first; first != nullptr; tmp = first) {
			first = first->next;
			delete tmp;
		}
	}

	bool isEmpty() const {
		return first == nullptr;
	}

	int size() const {
		return n;
	}

	void push(T item) {
		Node *tmp = first;
		first = new Node(item);
		first->next = tmp;
		++n;
	}

	T pop() {

		Node *tmp = first; 
		first = first->next;

		T item = tmp->item;
		delete tmp;
		--n;
		return item;
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
struct Stack<T>::Node {
	Node *next;
	T item;
	Node(T i): next(nullptr), item(i) { }
};

template <typename T>
class StackIterator {
	
 public:

	StackIterator(typename Stack<T>::Node *c): cur(c) { }

	bool operator == (const StackIterator<T>& that) {
		return cur == that.cur;
	}

	bool operator != (const StackIterator<T>& that) {
		return !(*this == that);
	}

	StackIterator<T>& operator ++ () {
		cur = cur->next;
		return *this;
	}

	StackIterator<T> operator ++ (int i) {
		typename Stack<T>::Node *tmp = cur;
		cur = cur->next;
		return *tmp;
	}

	T& operator * () { return cur->item; }
	const T& operator * () const { return cur->item; }

 private:

	typename Stack<T>::Node *cur;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Stack<T>& stk) {
	for (const auto& item : stk) os << stk << " ";
	return os;
} 

}
		
#endif
