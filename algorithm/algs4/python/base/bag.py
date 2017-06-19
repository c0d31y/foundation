import sys

class Bag(object):

    class __Node(object):
        
        def __init__(self, item, next):
            self.item = item
            self.next = next

    def __init__(self):
        self._first = None
        self._cur = None
        self._n = 0

    def __iter__(self):
        self._cur = self._first
        return self

    def __next__(self):
        if self._cur is None:
            raise StopIteration
        else:
            item = self._cur.item
            self._cur = self._cur.next
            return item

    def __repr__(self):
        return " ".join(self)
            
    def size(self):
        return self._n

    def is_emtpy(self):
        return self._first is None

    def add(self, item):
        self._first = self.__Node(item, self._first)
        self._n += 1

if __name__ == "__main__":
            
    bag = Bag()
    for line in sys.stdin:
        for item in line.strip().split():
            bag.add(item)
    print(bag, " (%d items in bag)" % bag.size())

            
        
        
