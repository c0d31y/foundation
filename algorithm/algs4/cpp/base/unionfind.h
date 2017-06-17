#ifndef __BASE_UNIONFIND_H__
#define __BASE_UNIONFIND_H__

namespace algs4 {

class UnionFind;
class QuickFind;
class QuickUnion;
class WeightedQuickUnion;

typedef WeightedQuickUnion UF;
	
class UnionFind {

 public:
	
	explicit UnionFind(int size): n(size), cnt(n) {
		id = new int[n];
		for (int i = 0; i < n; ++i) id[i] = i;
	}

	virtual ~UnionFind() { delete[] id; } 

	int count() const { return cnt; }

	bool same(int p, int q) const { return find(p) == find(q); }

	virtual int find(int p) const = 0;

	virtual void connect(int p, int q) = 0;

 protected:
	
	int *id;
	int n;
	int cnt;
};

class QuickFind: public UnionFind { 
 public:
	explicit QuickFind(int size): UnionFind(size) { }
	int find(int p) const override;
	void connect(int p, int q) override;
};

class QuickUnion: public UnionFind { 
 public:
	explicit QuickUnion(int size): UnionFind(size) { }
	int find(int p) const override;
	void connect(int p, int q) override;
};

class WeightedQuickUnion: public UnionFind {

 public:

	WeightedQuickUnion(int size): UnionFind(size) {
		sz = new int[n];
		for (int i = 0; i < n; ++i) sz[i] = 1;
	}

	~WeightedQuickUnion() { delete[] sz; } 

	int find(int p) const override;
	void connect(int p, int q) override;

 protected:
	int *sz; 
};

}
#endif
