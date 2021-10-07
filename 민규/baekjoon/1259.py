true_a = "yes"
false_a = "no"

while True:
 data0 = input()

 if data0 == "0":
  break

 if data0 == "".join(reversed(data0)):
  print(true_a)

 else:
  print(false_a)


 
  
