#ifndef __SORT_MERGESORT_H__
#define __SORT_MERGESORT_H__

#include "array.h"

namespace algs4 {
	
class MergeSort {

 public:

	template <typename T>
	static void sort(Array<T>& a) {
	
		int n = a.size();	
		Array<T> aux(n);
		for (int i = 0; i < n; ++i) aux[i] = a[i];  
		sort(a, aux, 0, n);	

	}

	template <typename T>
	static void sort_bu(Array<T>& a) {
		
		int n = a.size();
		Array<T> aux(n);
		
		for (int sz = 1; sz < n; sz += sz)
			for (int lo = 0; lo + sz< n; lo += 2*sz) 
				merge(a, aux, lo, lo + sz, min(lo + 2*sz, n)); 
	}

 private:

	template <typename T>
	static void sort(Array<T>& a, Array<T>& aux, int lo, int hi) {

		if (hi - 1<= lo) return;
		int mid = lo + (hi - lo) / 2;
		sort(a, aux, lo, mid);
		sort(a, aux, mid, hi);
		merge(a, aux, lo, mid, hi); 

	}

	template <typename T>
	static void merge(Array<T>& a, Array<T>& aux, int lo, int mid, int hi) {

		for (int k = lo; k < hi; ++k) aux[k] = a[k];
		for (int i = lo, j = mid, k = lo; k < hi; ++k) {
			if (i >= mid) a[k] = aux[j++];
			else if (j >= hi) a[k] = aux[i++];
			else if (less(aux[i], aux[j])) a[k] = aux[i++];
			else a[k] = aux[j++];
		}
	}

	template <typename T>
	static bool less(const T& v, const T& w) { return v < w; }

	template <typename T>
	static const T& min(const T& v, const T& w) { return v < w ? v : w; }
};

}

#endif
