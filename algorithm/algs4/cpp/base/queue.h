#ifndef __BASE_QUEUE_H__
#define __BASE_QUEUE_H__

#include <iostream>

namespace algs4 {
	
template <typename T>
class QueueIterator;

template <typename T>
class Queue;

template <typename T>
class Queue {
	
	struct Node;
	
	template <typename U>
	friend class QueueIterator;

 public:

	typedef QueueIterator<T> iterator;

	Queue(): first(nullptr), last(nullptr), n(0) { }

	~Queue() {
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

	void enqueue(T item) {

		Node *tmp = last;
		last = new Node(item); 
		if (first == nullptr) first = last;
		else              tmp->next = last;
		++n;

	}

	T dequeue() {

		T item = first->item;  
		Node *tmp = first;
		first = first->next;
		if (first == nullptr) last = nullptr;

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
	
	Node *first, *last;
	int n;
};

template <typename T>
struct Queue<T>::Node {
	Node *next;
	T item;
	Node(T i): item(i), next(nullptr) { }
};

template <typename T>
class QueueIterator {
	
 public:
	QueueIterator(typename Queue<T>::Node *c): cur(c) { }

	bool operator == (const QueueIterator<T>& that) {
		return cur == that.cur;
	}

	bool operator != (const QueueIterator<T>& that) {
		return !(*this == that);
	}

	QueueIterator& operator ++ () {
		cur = cur->next;
		return *this;
	}  

	QueueIterator operator ++ (int i) {
		typename Queue<T>::Node *tmp = cur;
		cur = cur->next;
		return *tmp;
	}

  T& operator * () const {
		return cur->item;  
	}

 private:
	typename Queue<T>::Node cur;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Queue<T> queue) {
	for (const auto& item: queue) os << item << " ";
	return os;
}

}

#endif
