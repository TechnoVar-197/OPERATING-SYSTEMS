import threading
import time
class testAndSet():
    #lock variable used in test and set is defined here
    Lock = 0
    def test(self,*args):
        if self.Lock == 0:
            # The critical section goes here...
            self.criticalsection(args[0])
        else:
            #while other process is executing current process is waiting
            while self.Lock == 1:
                print(f"Process {args[0]} waiting")
    def criticalsection(self,i):
        self.Lock = 1
        print(f'Process {i} Entered Critical Section.\nPerform operation on shared memory')
        #exit section
        self.Lock = 0
        print(f'Process {i} exited  Critical Section')
    def main(self):
        t1 = threading.Thread(target = self.test, args = (0,))
        t1.start()
        t2 = threading.Thread(target = self.test, args = (1,))
        t2.start()
        t3 = threading.Thread(target = self.test, args = (2,))
        t3.start()
        t4 = threading.Thread(target = self.test, args = (3,))
        t4.start()
        t5 = threading.Thread(target = self.test, args = (4,))
        t5.start()
if __name__=="__main__":
    t = testAndSet()
    t.main()
