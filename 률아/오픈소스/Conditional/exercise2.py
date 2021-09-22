time="03:23"
h=time[:2]
m=time[3:]

if int(m)<30:
    h=str(int(h)-1)
    if int(h)<0:
        h="23"
    elif len(h)==1:
        h="0"+h
m=str((int(m)+30)%60)
if len(m)==1:
    m="0"+m
print("%s:%s"%(h,m))