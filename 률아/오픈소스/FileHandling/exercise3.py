import re
def search(name):
    fr=open("C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/FileHandling/student.txt",'r')
    line=fr.readline()
    check=0
    while line:
        list=re.split('[|\n]',line)
        if list[0]==name:
            check=1
            print("average:{0},grade:{1}".format(list[4],list[5]))
            break
        line=fr.readline()
    if check==0:
        print("없음")

search('Sun')
search('Jacob')
search('Yuna')