from random import *

class Queue:
    def __init__(self) -> None:
        self.queue=[]
    def isEmpty(self):
        return len(self.queue)==0
    def enqueue(self, num):
        self.queue.append(num)
    def peek(self):
        if self.isEmpty():
            return "None"
        return self.queue[0]
    def dequeue(self):
        if self.isEmpty()==0:
            del self.queue[0]
    def queueSize(self):
        return len(self.queue)

i=0
Q=Queue()

while i<10:
    num=randint(1,2)

    print("----%d step----"%(i+1))

    if num==1:
        Q.enqueue(i)
    else:
        num=Q.dequeue()
    
    print("Current queue: ", Q.queue)
    print("Peek data: ", Q.peek())
    print("Queue size: ", Q.queueSize())

    i+=1
