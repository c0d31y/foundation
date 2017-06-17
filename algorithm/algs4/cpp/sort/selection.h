#ifndef __SORT_SELECTION_H__
#define __SORT_SELECTION_H__

#include "array.h"
#include "sort.h"

namespace algs4 {

class Selection {

 public:
	
	template <typename T>
  static void sort(Array<T>& a) { 

		int n = a.size();
		for (int i = 0; i < n; ++i) {
			int min = i;
			for (int j = i + 1; j < n; ++j)
				if (less(a[j], a[min])) min = j;
			exch(a[i], a[min]);
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
