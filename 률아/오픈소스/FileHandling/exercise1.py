f=open("C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/FileHandling/test.txt","a")
f2=open("C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/FileHandling/test_copy.txt", "w")
f.write("Engine vibrations can harm phones'\nOptical-image stabilisation or closed-loop autofocus systems, it says.\nOwners of acooters and mopeds should also use vibration-dampening mounts\n")
fr=open("C:/Users/Administrator/source/repos/CodingTest/률아/오픈소스/FileHandling/test.txt","r")

while True:
    line=fr.readline()
    if not line: break
    f2.write(line)    
f.close()
fr.close()
f2.close()