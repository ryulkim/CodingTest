class Shelf:
    def __init__(self) -> None:
        self.box=[[],[],[],[]]
    def addNum(self, num):
        if num>=0 and num<=3:
            self.box[num].append(num)
            self.floor=num
        else:
            if self.isFull(self.floor):
                print("%d층은 꽉차서 더이상 공간이 없습니다."%(self.floor+1))
                return
            self.box[self.floor].append(num)
    def delNum(self, num):
        floor=num*(-1)-1
        if self.isEmpty(floor):
            print("%d층은 비어서 제거할 숫자가 없습니다."%(floor+1))
            return
        del self.box[floor][0]
    def levelSize(self, num):
        return len(self.box[num])
    def isFull(self, num):
        return len(self.box[num])==4
    def isEmpty(self, num):
        return len(self.box[num])==0

S=Shelf()
num=0
print("-4<=n<=-1: 각 층의 최근 입력숫자 제거, 나머지 음수: 종료")
while num>-5:
    num=int(input("0혹은 양수 입력: "))

    if num>=-4 and num<=-1:
        S.delNum(num)

    elif num<-4:
        print("종료합니다")
        break
    else:
        S.addNum(num)
    print("--> 현재 box 상태: ",S.box)