num=1

def input_num():
    a=input("2자리 자연수를 입력하세요: ")
    if(len(a)==2):
        return a;
    else:
        print("2자리 자연수가 아닙니다. 다시 입력하세요.")
        return input_num()
def mul(fir, sec):
    print("  %d\nX %d\n----\n %d\n%d\n----\n%d"%(fir,sec,fir*(sec%10),fir*(sec//10),fir*sec))

print("%d. %d번째 2자리 자연수 출력"%(num,num))
one=int(input_num())
num+=1
print("%d. %d번째 2자리 자연수 출력"%(num,num))
two=int(input_num())
mul(one,two)


