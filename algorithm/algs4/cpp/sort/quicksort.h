#ifndef __SORT_QUICKSORT_H__
#define __SORT_QUICKSORT_H__

#include "array.h"

namespace algs4 {

class QuickSort {

 public:

  template <typename T>
	static void sort(Array<T>& a) {
		sort(a, 0, a.size());
	}

	template <typename T>
	static void sort_3way(Array<T>& a) {
		sort_3way(a, 0, a.size());
	}

 private:

	template <typename T>
  static void sort(Array<T>& a, int lo, int hi) {
		if (hi - 1 <= lo) return;

		int j = partition(a, lo, hi);
		sort(a, lo, j);
		sort(a, j + 1, hi);
	} 

	template <typename T>
	static int partition(Array<T>& a, int lo, int hi) {
		
		int i = lo, j = hi;		
		while (true) {
			while (less(a[++i], a[lo])) if (i == hi - 1) break;
			while (less(a[lo], a[--j])) if (j == lo) break;
			
			if (i >= j) break;
			exch(a[i], a[j]);
		}
		
		exch(a[lo], a[j]); 
		return j;
	}

	template <typename T>
	static void sort_3way(Array<T>& a, int lo, int hi) {
	
		if (hi - 1 <= lo) return;
		int lt = lo, i = lo + 1, gt = hi - 1;
		T v = a[lo];
		while (i <= gt) {
			if (a[i] < v) exch(a[lt++], a[i++]);
			else if (a[i] > v) exch(a[i], a[gt--]);
			else i++;
		}	

		sort_3way(a, lo, lt);
		sort_3way(a, gt + 1, hi);
	}

	template <typename T>
	static bool less(const T& v, const T& w) { return v < w; }

	template <typename T>
	static void exch(T& v, T& w) { T t = v; v = w; w = t; }
};

}

#endif
