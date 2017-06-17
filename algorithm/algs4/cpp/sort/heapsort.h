#ifndef __SORT_HEAPSORT_H__
#define __SORT_HEAPSORT_H__

#include "array.h"
#include "minpq.h"

namespace algs4 {

class HeapSort {

 public:

	template <typename T>
	static void sort(Array<T>& a) {

		int n = a.size();
		for (int k = n / 2; k  >= 1; --k) sink(a, k, n);
		
		while (n > 1) {
			exch(a, 1, n--);
			sink(a, 1, n);
		}
	}
		
 private: 

	template <typename T>
	static void sink(Array<T>& a, int k, int n) {
		while ( 2 * k <= n) {
			int j = 2 * k;
			if (j < n && less(a, j, j + 1)) ++j;
			if (!less(a, k, j)) break;
			exch(a, k, j);
			k = j;
		}
	} 

	template <typename T>
	static bool less(Array<T>& a, int i, int j) { 
		return a[i - 1] < a[j - 1];
	} 

	template <typename T>
	static void exch(Array<T>& a, int i, int j) {
		T tmp = a[i - 1]; a[i - 1] = a[j - 1]; a[j - 1] = tmp;
	} 
};

}

#endif
