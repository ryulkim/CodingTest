list=[55,90,89,76,37,100,67]

for (idx,i) in enumerate(list, start=0):
    if(i>=90 and i<100):
        print("%d번 학생은 %d점으로 A입니다."%(idx+1,i))
    elif i>=80 and i<90:
        print("%d번 학생은 %d점으로 B입니다."%(idx+1,i))
    elif i>=70 and i<80:
        print("%d번 학생은 %d점으로 C입니다."%(idx+1,i))
    elif i>=60 and i<70:
        print("%d번 학생은 %d점으로 D입니다."%(idx+1,i))
    else:
        print("%d번 학생은 %d점으로 F입니다."%(idx+1,i))