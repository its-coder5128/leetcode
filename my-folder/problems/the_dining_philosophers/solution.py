from threading import Semaphore

class DiningPhilosophers:
    def __init__(self):
        self.mutex = Semaphore(1)
        self.semArray = [Semaphore(1) for _ in range(5)]

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        self.mutex.acquire()
        # self.semArray[philosopher%5].acquire()
        pickRightFork()
        # self.semArray[(philosopher + 1)%5].acquire()
        pickLeftFork()
        eat()
        putRightFork()
        putLeftFork()
        self.mutex.release()


        # self.semArray[philosopher%5].release()
        # self.semArray[(philosopher + 1)%5].release()
        
        