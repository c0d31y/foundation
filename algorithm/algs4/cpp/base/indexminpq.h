#ifndef __BASE_INDEXMINPQ_H__
#define __BASE_INDEXMINPQ_H__

namespace algs4 {

template <typename T>
class IndexMinPQ {

 public:
	
	IndexMinPQ(int c): capacity(c), n(0) {
		pq = new int[c + 1];
		qp = new int[c + 1];
		keys = new T[c + 1];
		for (int i = 0; i < c; ++i) qp[i] = -1;
	}

	~IndexMinPQ() {
		delete[] pq;
		delete[] qp;
		delete[] keys;
	}

	bool isEmpty() const { return n == 0; }
	int size() const { return n; } 
	int min() const { return pq[1]; }

	bool contains(int i) const { return qp[i] != -1; }
	void change(int i, T key) { keys[i] = key; }

	void insert(int i, T key) {
		pq[++n] = i;
		qp[i] = n;
		keys[i] = key;
		swim(n);
	}

	int delmin() {
		int min = pq[1];
		exch(1, n--);
		qp[min] = -1;
		sink(1);
		return min;
	}

 private:

	int n;
	int capacity;
	
	int *pq;
	int *qp;
	T* keys;

	void swim(int k) {
		while (k > 1 && less(k, k / 2)) {
			exch(k , k / 2);
			k = k / 2;
		}
	}

	void sink(int k) {
		while ( 2 * k <= n) {
			int j = 2 * k;
			if (j < n && less(j + 1, j)) ++j;
			if (less(k, j)) break;
			exch(k, j);
			k = j;
		}
	}

	bool less(int i, int j) const { return keys[pq[i]] < keys[pq[j]]; }
	void exch(int i, int j) {
		int t = pq[i]; pq[i] = pq[j]; pq[j] = t;
		qp[pq[i]] = i;
		qp[pq[j]] = j;
	}
};

}

#endif
