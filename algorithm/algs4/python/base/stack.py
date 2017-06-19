import sys

class Stack(object):

    class __Node(object):
        
        def __init__(self, item):
            self.item = item
            self.next = None

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

    def is_empty(self):
        return self._first is None

    def push(self, item):
        tmp = self._first
        self._first = self.__Node(item)
        self._first.next = tmp
        self._n += 1
    
    def pop(self):
        item = self._first.item
        self._first = self._first.next
        self._n -= 1
        return item

if __name__ == "__main__":
    
    stk = Stack()
    for line in sys.stdin:
        for item in line.strip().split():
            if item == "-": print(stk.pop(), end=" ")
            else:           stk.push(item)
    print("(%d items left on stack)" % stk.size())
        
        
    
        
