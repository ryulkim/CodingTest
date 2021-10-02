global file_a
file_a = open('cafe.txt','r')

class Menu:

 orderList = []
 total = 0

 def __init__(self):
  Menu.orderList = []
  Menu.total = 0


 def addMenu(self,f):
  while True:
    line = f.readline()
    if not line: break    
    line2 = line.split(',')
    Menu.orderList.append([int(line2[0]),line2[1], int(line2[2]), int(line2[3])])
    

  f.close()

 def printMenu(self):
  print("======================================")
  for i in Menu.orderList:
   print(str(i[0]) + "." + str(i[1]) +  " 금액 : " + str(i[2]) + "원 재고 : " + str(i[3]))
  print("======================================")
  print("end를 입력하시면 주문서로 돌아갑니다")


menu_a = Menu()

class Order:
 orderResult = [[0,0]]

 def __init__(self):
  orderResult = [[0,0]]
  
 def orderMenu(self, menuNum):
  menu_a.printMenu()

  if(menuNum == "end"):
   print("총 주문 수량: " + str(Order.orderResult[0][0]) + " 개, 총 주문 금액: " + str(Order.orderResult[0][1]))
   return
  
  menuNum = int(menuNum) 
  
  if(menuNum >= len(menu_a.orderList)):
   print("존재하지 않는 메뉴입니다")

  else:
   menuNum -= 1
   print("선택한 메뉴의 수량을 입력해주세요")
   menu_num = int(input())

   if(menu_a.orderList[menuNum][3] <= 0):
    print("품절되었습니다. 다른메뉴를 선택해주세요")

   elif(menu_a.orderList[menuNum][3] - menu_num < 0):
    print("수량이 부족합니다")
    menu_num = int(input())

   menu_a.orderList[menuNum][3] -= menu_num
   Order.orderResult[0][0] += menu_num
   menu_a.total += menu_num * menu_a.orderList[menuNum][2]
   Order.orderResult[0][1] += menu_num * menu_a.orderList[menuNum][2]

  print("추가로 주문할 메뉴 번호를 입력해주세요")
  menuNum1 = input()
  Order.orderMenu(self,menuNum1)

class Manage:
 ManageResult = [[0,0]]

 def __init__(self):
  ManageResult = [[0,0]]

 def Management(self, menuNum):
  menu_a.printMenu()


  if(menuNum == "end"):
   print("총 입고 수량: " + str(Manage.ManageResult[0][0]) + " 개, 총 입고 금액: " + str(Manage.ManageResult[0][1]))
   return

  menuNum = int(menuNum) 
  
  if(menuNum >= len(menu_a.orderList)):
   print("존재하지 않는 메뉴입니다")

  else:
   menuNum -= 1
   print("선택한 메뉴의 수량을 입력해주세요")
   menu_num = int(input())

   menu_a.orderList[menuNum][3] += menu_num
   Manage.ManageResult[0][0] += menu_num
   menu_a.total -= menu_num * menu_a.orderList[menuNum][2]
   Manage.ManageResult[0][1] += menu_num * menu_a.orderList[menuNum][2]

  print("추가로 입고할 메뉴 번호를 입력해주세요")
  menuNum1 = input()
  Manage.Management(self,menuNum1)


menu_a.addMenu(file_a)


order1 = Order()
manage1 = Manage()

while(True):
 print("=============")
 print("   주문서      ")
 print("=============")
 print("1. 커피 주문하기")
 print("2. 커피 매출확인")
 print("3. 커피 입고하기")
 print("4. 종료하기")
 print("=============")

 print("원하시는 주문 번호를 입력해주세요")
 command = int(input())

 if(command == 1):
  menu_a.printMenu()
  print("주문할 메뉴 번호를 입력해주세요")
  menuNum = input()
  order1.orderMenu(menuNum)

 elif(command == 2):
  print("총 매출은 " + str(menu_a.total) + "원입니다.")

 elif(command == 3):
  menu_a.printMenu()
  print("입고할 메뉴 번호를 입력해주세요")
  menuNum = input()
  manage1.Management(menuNum)

 else: break 
