#ifndef __SORT_INSERTION_H__
#define __SORT_INSERTION_H__

#include "array.h"
namespace algs4 {

class Insertion {

 public:
	
	template <typename T>
	static void sort(Array<T>& a) {
		int n = a.size();
		for (int i = 1; i < n; ++i) 
			for (int j = i; j > 0 && less(a[j], a[j-1]); --j)
				exch(a[j], a[j-1]); 
	}
 
 private:

	template <typename T>
	static bool less(const T& v, const T& w) { return v < w; }

	template <typename T>
	static void exch(T& v, T& w) { T t = v; v = w; w = t; }
};

}

#endif
