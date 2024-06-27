from threading import Semaphore
class Foo:
    def __init__(self):
        self.gates = (Semaphore(0),Semaphore(0));


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.gates[0].release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.gates[0].acquire()
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.gates[1].release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        
        self.gates[1].acquire()
        # printThird() outputs "third". Do not change or remove this line.
        printThird()