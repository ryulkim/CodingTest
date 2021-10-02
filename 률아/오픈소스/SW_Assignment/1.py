print("1. 1번째 n자리 정수 출력")
a=input("n자리 정수를 입력하세요: ")
a_len=len(a)
a=int(a)

print("2. 2번째 n자리 정수 출력")
b=input("n자리 정수를 입력하세요: ")
b_len=len(b)

print("3. 곱셈 결과 출력")

length=len(str(a*int(b)))
length=length+2 if length<4 else length

print(str(a).rjust(length))
print("X"+b.rjust(length-1))
print("-"*length)


posi=length

for i in range(b_len-1,-1,-1):
    if b[i]=='-':
        break
    num=str(a*int(b[i]))
    print(num.rjust(posi))
    posi=posi-1
print("-"*length)
print(str(a*int(b)).rjust(length))