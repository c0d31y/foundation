#ifndef __BASE_MINPQ_H__
#define __BASE_MINPQ_H__

namespace algs4 {

template <typename T>
class MinPQ {
 
 public:
	
	MinPQ(int c): capacity(c), n(0) {
		pq = new T[capacity + 1];
	}

	~MinPQ() { delete[] pq; }

	bool empty() const { return n == 0; }
	int size() const { return n; }

	void insert(T key) {
		pq[++n] = key;
		swim(n);
	}

	T delmin() {
		T min = pq[1];
		exch(1, n--);
		sink(1);
		return min;
	}

 private:

	int capacity;
  int n; 	
	T *pq;

  void swim(int k) {
		while (k > 1 && less(k, k / 2)) {
			exch(k, k / 2);
			k = k / 2;
		}
	}

	void sink(int k) {
		while (2 * k <= n) {
			int j = 2 * k;
			if (j < n && less(j + 1, j)) ++j;
			if (less(k, j)) break;
			exch(k, j);
			k = j;
		}
	}

	bool less(int i, int j)  const { return pq[i] < pq[j]; }
  void exch(int i, int j) { T tmp = pq[i]; pq[i] = pq[j]; pq[j] = tmp; }	
};

}

#endif
