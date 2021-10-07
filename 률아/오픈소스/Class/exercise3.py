class Square:
    def __init__(self, x, y, len):
        self.center=(x,y)
        self.len=len
    def area(self):
        return self.len**2
class Common_area(Square):
    def common(self, other):
        x1,x2=self.center[0]-self.len/2,self.center[0]+self.len/2
        y1,y2=self.center[1]+self.len/2,self.center[1]-self.len/2
        x3,x4=other.center[0]-other.len/2,other.center[0]+other.len/2
        y3,y4=other.center[1]+other.len/2,other.center[1]-other.len/2

        if x1>x4:
            return 0
        elif x2<x3:
            return 0
        elif y1<y4:
            return 0
        elif y2>y3:
            return 0
        
        xl=max(x1,x3)
        xr=min(x2,x4)
        yu=min(y1,y3)
        yd=max(y2,y4)
        x=xr-xl
        y=yu-yd

        return x*y




print("첫 번째 정사각형의 중심좌표와 한 변의 길이를 입력하세요")
x=int(input("x좌표:"))
y=int(input("y좌표:"))
r=int(input("한 변의 길이:"))
a=Common_area(x,y,r)

print("두 번째 정사각형의 중심좌표와 한 변의 길이를 입력하세요")
x=int(input("x좌표:"))
y=int(input("y좌표:"))
r=int(input("한 변의 길이:"))
b=Common_area(x,y,r)



print("첫 번째 정사각형의 좌표, 넓이 : {0} {1}".format(a.center,a.area()))
print("두 번째 정사각형의 좌표, 넓이 : ",b.center,' ',b.area())
print("두 정사각형의 공통 넓이: {:.2f}".format(a.common(b)))
if a.common(b)==0:
    print("겹치는 부분이 없습니다")