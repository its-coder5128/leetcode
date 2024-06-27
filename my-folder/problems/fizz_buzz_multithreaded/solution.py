from threading import Semaphore
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.done = False
        self.f = Semaphore(0)
        self.b = Semaphore(0)
        self.fb = Semaphore(0)
        self.num = Semaphore(1)


    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            self.f.acquire()
            if self.done:
                break  
            printFizz()
            self.num.release()


    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True :
            self.b.acquire()
            if self.done:
                break    
            printBuzz()
            self.num.release()


    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            self.fb.acquire()
            if self.done:
                break     
            printFizzBuzz()
            self.num.release()


    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,self.n + 1):
            self.num.acquire()
            if i % 15 == 0:
                self.fb.release()
            elif i % 3 == 0:
                self.f.release()
            elif i % 5 == 0:
                self.b.release()
            else :
                printNumber(i)
                self.num.release()
        
        self.num.acquire()
        self.done = True
        self.f.release()
        self.b.release()
        self.fb.release()