import sys

class WeightedQuickUnion(object):

    def __init__(self, size):
        self._id = [i for i in range(size)]
        self._sz = [1 for _ in range(size)]
        self._cnt = size 

    def count(self):
        return self._cnt 

    def find(self, p):
        while self._id[p] != p:
            self._id[p] = self._id[self._id[p]]
            p = self._id[p]
        return p

    def same(self, p, q):
        return self.find(p) == self.find(q)

    def connect(self, p, q):
        i = self.find(p)
        j = self.find(q)
        if i == j: return

        if self._sz[i] < self._sz[j]:
            self._id[i] = j
            self._sz[j] += self._sz[i]
        else:
            self._id[j] = i
            self._sz[i] += self._sz[j]
        self._cnt -= 1

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    uf = WeightedQuickUnion(size)
    cnt = 0
    while True:
        line = sys.stdin.readline()
        if not line: break

        p, q = map(int, line.split())
        if not uf.same(p, q):
            uf.connect(p, q)
            if cnt < 20: 
                print("%d %d" % (p, q)) 
            elif cnt == 20:
                print("... ...")
            cnt += 1

    print("%d components" % uf.count())

    
