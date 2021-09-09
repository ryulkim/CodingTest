
print("x:")
x = int(input())
print("y:")
y = int(input())


def mul(x,y):
 return x*y

sub = x - y
div = x/y

if sub < 0:
 sub = -sub
 div = y/x
 
print(str(x+y) + " " + str(sub) + " " + str(x*y) + " " + str(div))

print("and" + str(mul(x,y)))


for x2 in range(0,x%10):
 line = ""
 for x3 in range(0, x%10 - x2):
  line += "*"  
 print(line) 
