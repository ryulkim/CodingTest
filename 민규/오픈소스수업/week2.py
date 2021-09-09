import datetime
import numpy as np

global name
global phone

if True:
 name = input()
 phone = input()
 
 #name[0].upper() 
 print(name.capitalize() + " " + phone.replace("-","")) #exercise1
 
 
 list1 = [1,3,5,7,9]
 list2 = [2,4,6,8,10]
 list3 = list1 + list2
 list3.sort(reverse = True)
 print(list3) #exercise2
 
 
 x = (1,2,3)
 y = ('a','b')
 z = x + y
 print("drop '" + z[len(z) -1] + "':")
 print(z[:len(z) -1]) #excercise3
 
 
 
 dic = { 'Kim' : 'Math', 'Lee' : 'English','Han' : 'Art', 'Ahn' : 'Physics'}
 print(dic)
 print(dic.keys())
 print(dic.values()) #exercise 4
 
 
 a = (5, -5)
 b = (-5, 5)
 
 
 if a[0] == b[0] and a[1] == b[1]:
  print("같음")
  
 elif a[0] == -b[0] and a[1] == b[1]:
  print("x축 대칭") 
 
 elif a[0] == b[0] and a[1] == -b[1]:
  print("y축 대칭")
 
 elif a[0] == -b[0] and a[1] == -b[1]:
  print("원점 대칭") 
 
 else: print("nothing") #excercise 2-1
 
 timestr = "10:45"
 tm = datetime.datetime.strptime(timestr,"%I:%M")
 tm -= datetime.timedelta(minutes=30)
 print(str(tm.hour) + ":" + str(tm.minute)) #excercise 2-2
 
 
 a = "가위"
 b = "바위"
 dic_a = {'보':0, '가위':1, '바위':2}
 
 
 if dic_a[a]==dic_a[b]:
  print("draw")
  
 elif dic_a[a] < dic_a[b]:
  if(dic_a[b] - dic_a[a] > 1):
   print(a)
  else: print(b) #excercise 2-3
  
  
 while(False):
  a = 1
  #if(a==1):
  #elif(a==2):
  #elif(a==3):
  #elif(a==4):
  #else: break #exercise 3-1
  
 data=[100, 90, 80, 55, 95, 80, 65, 75, 70, 90]
 print(np.mean(data))
 print(np.var(data)) #exercise 3-2
  
  
grade = {90:'A', 80:'B', 70:'C', 60:'D', 0:'F'} #exercise 3-3

#소수 구하기 exercise 3-4
  
list_m = [[1, 2], [5, 4], [6, 6], [7, 8], [9, 10]]
list_n = np.ravel(list_m)
print(list_n) #exercise 3-5

 
 
 
 
 
 
