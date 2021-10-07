path="C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/SW_Assignment/"

class Menu:
    def __init__(self, f):
        self.orderList={}
        self.total=0
        self.addMenu(f)
    def addMenu(self, f):
        file=path+f
        fr=open(file,'r',encoding='utf-8')
        line=fr.readline()
        while line:
            line=line.rstrip()
            list=line.split(', ')
            list[2]=int(list[2])
            list[3]=int(list[3])
            self.orderList[list[0]]=list[1:]
            line=fr.readline()
        fr.close()
    def printMenu(self):
        print("\n===========================")
        for key, list in self.orderList.items():
            print("{0}.{1}   금액: {2}원 재고: {3}".format(key, list[0],list[1],list[2]))
        print("end를 입력하시면 주문서로 돌아갑니다.")
        print("===========================\n")


class Order:
    def __init__(self):
        self.orderResult=[0,0]
    def orderMenu(self, menuNum):
        while(True):
            cafe.printMenu()
            if cafe.orderList.get(menuNum):
                while(True):
                    print("선택한 메뉴의 수량을 입력해주세요")
                    num=int(input("input: "))
                    if cafe.orderList[menuNum][2]==0:
                        print("품절되었습니다. 다른 메뉴를 선택해주세요\n")
                        print("메뉴 번호를 다시 입력해주세요")
                        menuNum=input("input: ")
                        break
                    elif cafe.orderList[menuNum][2]<num:
                        print("수량이 부족합니다.")
                        cafe.printMenu()
                    else:
                        cafe.orderList[menuNum][2]-=num
                        self.orderResult[0]+=num
                        self.orderResult[1]+=cafe.orderList[menuNum][1]*num
                        print("추가로 주문할 메뉴 번호를 입력해주세요")
                        menuNum=input("input: ")
                        break
            elif menuNum=="end":
                print("주문내역")
                print("총 주문 수량: %d 개, 총 주문 금액: %d원"%(self.orderResult[0],self.orderResult[1]))
                cafe.total+=self.orderResult[1]
                break
            else:
                print("존재하지 않는 메뉴입니다.")
                print("메뉴 번호를 다시 입력해주세요")
                menuNum=input("input: ")
            
class Manage:
    def __init__(self):
        self.manageResult=[0,0]
    def Management(self,menuNum):
        while(True):
            cafe.printMenu()
            if cafe.orderList.get(menuNum):    
                print("선택한 메뉴의 수량을 입력해주세요")
                num=int(input("input: "))
                cafe.orderList[menuNum][2]+=num
                self.manageResult[0]+=num
                self.manageResult[1]+=num*cafe.orderList[menuNum][1]
                print("추가로 주문할 메뉴 번호를 입력해주세요")
                menuNum=input("input: ")
            elif menuNum=='end':
                cafe.printMenu()
                print("주문내역")
                print("총 주문 수량: %d 개, 총 주문 금액: %d원"%(self.manageResult[0],self.manageResult[1]))
                break
            else:
                print("존재하지 않는 메뉴입니다.")
                print("메뉴 번호를 다시 입력해주세요")
                menuNum=input("input: ")
    def toSale(self):
        print("총 매출은 %d입니다."%(cafe.total))
    


cafe=Menu("cafe.txt")
while(True):
    print("\n===============")
    print("    주문서")
    print("===============")
    print("1. 커피 주문하기")
    print("2. 커피 매출 확인")
    print("3. 커피 입고 하기")
    print("4. 종료하기")
    print("===============\n")
    print("원하시는 주문 번호를 입력해주세요")
    menuNum=input("input: ")

    if menuNum=='1':
        order=Order()
        print("주문할 메뉴 번호를 입력해주세요")
        orderNum=input("input: ")
        order.orderMenu(orderNum)
    elif menuNum=='2':
        manage=Manage()
        manage.toSale()
    elif menuNum=='3':
        manage=Manage()
        print("입고할 메뉴 번호를 입력해주세요")
        manageNum=input("input: ")
        manage.Management(manageNum)
    elif menuNum=='4':
        break
    else:
        print("주문번호가 틀렸습니다. 다시 입력해주세요")
