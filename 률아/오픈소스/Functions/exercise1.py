def Fact(num):
    if num<=0:
        return "error"
    if num==1:
        return 1
    return num*Fact(num-1)

print(Fact(5))
print(Fact(-1))