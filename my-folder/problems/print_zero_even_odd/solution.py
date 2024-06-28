from threading import Lock
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.z = Lock()
        self.o = Lock()
        self.e = Lock()
        self.o.acquire()
        self.e.acquire()

        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,self.n+1):
            self.z.acquire()
            printNumber(0)

            if i%2 == 0:
                self.e.release()
            else:
                self.o.release()

        if self.e.locked():        
            self.e.release()
        if self.o.locked():        
            self.o.release()


        
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2,self.n+1,2):
            self.e.acquire()
            printNumber(i)
            self.z.release()

        
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,self.n+1,2):
            self.o.acquire()
            printNumber(i)
            self.z.release()
        
        