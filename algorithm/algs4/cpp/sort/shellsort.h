#ifndef __SORT_SHELLSORT_H__
#define __SORT_SHELLSORT_H__

#include <array.h>

namespace algs4 {

class ShellSort {

 public:

	template <typename T>
	static void sort(Array<T>& a) {
		int n = a.size(), h = 0;
		while (h < n / 3) h = 3 * h + 1;
		while (h >= 1) {
			for (int i = h; i < n; ++i) {
				for (int j = i; j >= h && less(a[j], a[j-h]); j -= h)
					exch(a[j], a[j-h]);
			}
			h = h / 3;
		}
	}

 private:

	template <typename T>
	static bool less(const T& v, const T& w) { return v < w; }
	
	template <typename T>
	static void exch(T& v, T& w) { T t = v; v = w; w = t; }
};

}
#endif
