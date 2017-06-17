#ifndef __BASE_STACK_H__
#define __BASE_STACK_H__

namespace algs4 {

template <typename T>
class StackIteartor;

template <typename T>
class Stack;

template <typename T>
class Stack {

	struct Node;

	template <typename U>
	friend class StackIteartor;

 public:

	typedef StackIteartor<T> iterator;

	Stack(): first(nullptr), n(0) { }

	~Stack() {
		for (Node *tmp = first; first != nullptr; tmp = first) {
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

	void push(T item) {
		Node *tmp = first;
		first = new Node(item);
		first->next = tmp;
		++n;
	}

	T pop() {
		T item = first->item;
		first = first->next;
		--n;
		return item;
	}

	iterator begin() {
		return iterator(first);
	}

	iterator end() {
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

	T& operator * () const {
		return cur->item;
	}

 private:

	typename Stack<T>::Node *cur;
};

}
		
#endif
