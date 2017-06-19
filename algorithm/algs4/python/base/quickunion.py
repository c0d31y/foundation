import sys

class QuickUnion(object):

    def __init__(self, size):
        self._id = [i for i in range(size)]
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
        pr = self.find(p)
        qr = self.find(q)
        if pr == qr: return

        self._id[pr] = qr
        self._cnt -= 1

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    uf = QuickUnion(size)
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

    

