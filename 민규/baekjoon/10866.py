from sys import stdin
from collections import deque

none_a = -1
len_case = int(input())
list_a = deque()


def push_f(x):
 list_a.appendleft(x)


def push_b(x):
 list_a.append(x) 

def pop_f():
 if(list_a):
  print(list_a.popleft())

 else:
  print(none_a)

def pop_b():
 if(list_a):
  print(list_a.pop())

 else:
  print(none_a)

def size_a():
 print(len(list_a))


def empty_a():
 if(list_a):
  print(0)

 else:
  print(1) 

def front_a():
 if(list_a):
  print(list_a[0])

 else:
  print(none_a) 

def back_a():
 if(list_a):
  print(list_a[-1])

 else:
  print(none_a) 



for x in range(0,len_case):
 answer = stdin.readline().strip()
 if(answer.split()[0] == "push_front"):
  push_f(int(answer.split()[1]))

 elif(answer.split()[0] == "push_back"):
  push_b(int(answer.split()[1]))

 elif(answer == "pop_front"):
  pop_f()

 elif(answer == "pop_back"):
  pop_b() 

 elif(answer == "size"):
  size_a()

 elif(answer == "empty"):
  empty_a()   

 elif(answer == "front"):
  front_a()

 else:
  back_a()



 
  
