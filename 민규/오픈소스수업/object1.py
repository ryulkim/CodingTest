
print("1번째 n자리 정수 출력")
num1 = int(input())
print("2번째 n자리 정수 출력")
num2 = input()
answer = 0
index = 1;
s = ""
list_a = []

answer_0 = 0
len_a = len(str(num1 * int(num2)))

print("곱셈 결과 출력")
print(str(num1).rjust(len_a))
print(str("X " + num2).rjust(len_a))
print("-------------------")



for x in num2:
 if(x == '-'):
  s += " "
  continue

 answer_1 = int(x) * num1
 count = len(str(answer_0)) - len(str(answer_1)) 
 while(count >= 0):
  s += " "
  count = count - 1
   
 list_a.append(s + str(answer_1))
 answer_0 = answer_1
 
for i in reversed(list_a):
 print(i) 
 
print("-------------------") 
print(num1 * int(num2)) 



