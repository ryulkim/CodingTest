from sys import stdin

n = int(input())
i = 96
r = 1
m = 1234567891
answer = 0

str1 = stdin.readline()[:-1]
for x in str1:
 answer = (answer + r * (ord(x) - 96))%m
 r*= 31

print(answer) 
