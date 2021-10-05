def student(name, mid, fin, assign):
    aver=(mid+fin+assign)/3
    grade="C"
    fw=open("C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/FileHandling/student.txt",'a')
    if aver>=90 and aver<=100:
        grade="A"
        fw.write("{0}|{1}|{2}|{3}|{4:.2f}|{5}\n".format(name,mid,fin,assign,str(aver),grade))
    elif aver>=80:
        grade="B"
        fw.write("{0}|{1}|{2}|{3}|{4:.2f}|{5}\n".format(name,mid,fin,assign,aver,grade))
    else:
        fw.write("{0}|{1}|{2}|{3}|{4:.2f}|{5}\n".format(name,mid,fin,assign,aver,grade))

student('Jerry',90,89,99)
student('Eric',56,45,80)
student('Sun',20,79,60)
student('Jacob',40,39,98)