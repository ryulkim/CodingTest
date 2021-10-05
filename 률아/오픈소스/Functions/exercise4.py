def second_priority(s):
    answer=0
    for i in s:
        if i>="A"and i<="Z":
            answer+=1
    return answer
    

list=['A51E','12KB','KDD7','1Z92','P703','GP2Y','PPD4','PM7','03Q','A3']
e= sorted(list, key=lambda x : (len(x), second_priority(x), x))
print(e)