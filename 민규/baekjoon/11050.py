from sys import stdin
from collections import deque

line_a = input().split()
n = int(line_a[0])
k = int(line_a[1])

answer = 1

for x in range(0,k):
 answer *= (n-x) 

for x in range(0,k):
 answer = int(answer/(k-x)) 

print(answer)
