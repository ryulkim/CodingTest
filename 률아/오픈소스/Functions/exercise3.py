import math

def student_grade(n):
    i=0
    li=[]
    while i<n:
        x=int(input("학생%d의 점수를 입력하세요: "%i))
        if x>=0 and x<=100:
            li.append(x)
            i+=1
    return li
            
def grade_calculator(stu):
    aver=0
    devi=0
    max=[0,stu[0]]
    min=[0,stu[0]]
    for idx,i in enumerate(stu):
        aver+=i
        if max[1]<i:
            max[0]=idx
            max[1]=i
        if min[1]>i:
            min[0]=idx
            min[1]=i
    aver=aver/len(stu)
    for i in stu:
        devi+=(i-aver)*(i-aver)
    devi/=len(stu)
    devi=math.sqrt(devi)
    print("학생 점수:",stu)
    print("평균:",aver)
    print("표준편차:",devi)
    print("최고점: 학생%d %d"%(max[0],max[1]))
    print("최저점: 학생%d %d"%(min[0],min[1]))


num=int(input("학생 수를 입력하세요: "))
stu=student_grade(num)
grade_calculator(stu)
