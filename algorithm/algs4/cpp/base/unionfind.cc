#include "unionfind.h"

namespace algs4 {

int QuickFind::find(int p) const  { return id[p]; }

void QuickFind::connect(int p, int q) {
	int pr = find(p), qr = find(q);
	if (pr == qr) return;

	for (int i = 0; i < n; ++i)
		if (id[i] == pr) id[i] = qr;
	--cnt;
}

int QuickUnion::find(int p) const  {
	while (id[p] != p) { id[p] = id[id[p]]; p = id[p]; }
	return p;
}
		
void QuickUnion::connect(int p, int q) {
	int pr = find(p), qr = find(q);
	if (pr == qr) return;

	id[pr] = qr;
	--cnt;
}

int WeightedQuickUnion::find(int p) const  {
	while (id[p] != p) { id[p] = id[id[p]]; p = id[p]; }
	return p;
}

void WeightedQuickUnion::connect(int p, int q) {
	int pr = find(p), qr = find(q);
	if (pr == qr) return;

	if (sz[pr] < sz[qr]) { sz[qr] += sz[pr]; id[pr] = qr; }
	else 								 { sz[pr] += sz[qr]; id[qr] = pr; }
	--cnt;
}
	
}
