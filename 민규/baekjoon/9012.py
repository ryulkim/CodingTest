true_a = "YES"
false_a = "NO"

dic_a = {'(':1, ')':-1}

len_case = int(input())

for x in range(0,len_case):
 data0 = input()
 answer = 0
 for x in data0:
  answer += dic_a.get(x)
  if(answer < 0):
   break
 
 if(answer == 0):
  print(true_a)
 
 else:
  print(false_a)



 
  
