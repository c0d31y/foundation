import sys

class QuickFind(object):

    def __init__(self, size):
        self._id = [i for i in range(size)]
        self._cnt = size

    def count(self):
        return self._cnt

    def find(self, p):
        return self._id[p]

    def same(self, p, q):
        return self.find(p) == self.find(q)

    def connect(self, p, q):
        pr = self.find(p)
        qr = self.find(q)
        if pr == qr: return

        for i in range(len(self._id)):
            if self._id[i] == pr:
                self._id[i] = qr;
        self._cnt -= 1

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    uf = QuickFind(size)
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

    
