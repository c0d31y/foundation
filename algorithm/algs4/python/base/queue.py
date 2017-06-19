import sys

class Queue(object):

    class __Node(object):
        
        def __init__(self, item):
            self.item = item
            self.next = None

    def __init__(self):
        self._first = None
        self._last = None
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

    def is_empty(self):
        return self._first is None

    def enqueue(self, item):
        tmp = self._last
        self._last = self.__Node(item)
        if self._first is None:
            self._first = self._last
        else:
            tmp.next = self._last
        self._n += 1

    def dequeue(self):
        tmp = self._first
        self._first = self._first.next
        if self._first is None:
            self._last = None
            
        self._n -= 1
        return tmp.item
        

if __name__ == "__main__":

    queue = Queue()
    for line in sys.stdin:
        for item in line.strip().split():
            if item == "-": print(queue.dequeue(), end=" ")
            else:           queue.enqueue(item)
    print("(%d items left in queue)" % queue.size())
    
        
