from sys import stdin

small1 = {'(': 1 , ')' : -1}
big1 = {'[': 2 , ']' : -2}
data0 = ('yes', 'no')

while(True):
 str1 = stdin.readline()[:-1]
 answer_1 = 0
 answer_2 = 0
 data1 = [0]
 data2 = [0]

 if(str1 == "."):
  break

 for x in str1:
  if(small1.get(x) != None):
   if(answer_1 >=0):              
    answer_1 += small1.get(x)
    data1[-1] += small1.get(x)

    if(small1.get(x) > 0):
     data2.append(0)
 
    elif(len(data2) < 2 or data2.pop() != 0):
      break

   else:
    break 

  if(big1.get(x) != None):
   if(answer_2 >=0):
    answer_2 += big1.get(x)
    data2[-1] += big1.get(x)
    
    if(big1.get(x) > 0):
     data1.append(0)

    elif(len(data1) < 2  or data1.pop() != 0):
      break

   else:
    break   
 
 if answer_1 == 0 and answer_2 == 0:
  print(data0[0])
 else:
  print(data0[1]) 



