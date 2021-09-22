a=[4,3,2,9,7,18,22,13,6,24,37,12]
prime=[4,3,2,9,7,18,22,13,6,24,37,12]
composite=[]

for i in a:
    for j in range(2,i):
        if i%j==0:
            composite.append(i)
            prime.remove(i)
            break
print("Prime numbers: ",prime, len(prime))
print("Composite_numbers: ", composite, len(composite))
