from threading import Semaphore
class H2O:
    def __init__(self):
        self.h = Semaphore(1)
        self.o = Semaphore(0)
        self.cnt = 0



    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h.acquire()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        self.cnt += 1

        if self.cnt % 2 == 0:
            self.o.release()
        else:
            self.h.release()


    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.o.acquire()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()

        self.h.release()