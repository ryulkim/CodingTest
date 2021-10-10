data0 = [int(num)for num in input().split()]
data1 = [int(num)for num in input().split()]

data1.sort(reverse=True)
start = 0
end = data1[0]
return0 = 0

def calcul(seque):
 answer = 0
 for x in data1:
  if(x - seque > 0):
   answer += x - seque

 return answer  

while(start <= end):
 seque = int((start + end)/2)
 answer = calcul(seque)

 if(answer >= data0[1]):
  return0 = max(return0,seque)
  start = seque + 1

 else:
  end = seque - 1

print(return0)

