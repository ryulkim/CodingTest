list=[100,90,80,55,95,80,65,75,70,90]
sum=0

for i in list:
    sum+=i
aver=sum/len(list)
sum=0
for i in list:
    sum+=(i-aver)*(i-aver)
var=sum/len(list)

print("Means : %.1f\nVariance : %.1f"%(aver,var))