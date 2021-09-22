player1="가위"
player2="바위"

if player1==player2:
    print("draw")

if player1=="가위":
    if player2=="바위":
        print("player2 win")
    elif player2=="보":
        print("player1 win")
elif player1=="바위":
    if player2=="가위":
        print("player1 win")
    elif player2=="보":
        print("player2 win")
elif player1=="보":
    if player2=="가위":
        print("player2 win")
    elif player2=="바위":
        print("player1 win")