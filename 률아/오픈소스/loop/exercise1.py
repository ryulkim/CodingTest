coin=0;
print("1: Insert coin | 2: Item list | 3: Select fruit | 4: Change money | Q: exit");

while 1:
    num=input("Please select menu: ");
    if num=="1":
        amount=input("How much money do you want to put in? ");
        coin+= int(amount);
        print('You insert {0} coins'.format(amount));
    elif num=="2":
        print('::::1. Orange: 300 :::: :::: 2. Shine muscat: 1000::::');
    elif num=="3":
        select=input("Which fruit do you want?");
        if select=="1":
            print("You get an orange");
            coin-=300;
        elif select=="2":
            print("You get an shine muscat");
            coin-=1000;
        print("You have %d coins"%coin);
    elif num=="4":
        print("You get %d coins back"% coin);
        coin=0;
    elif num=="Q":
        print("End");
        break;