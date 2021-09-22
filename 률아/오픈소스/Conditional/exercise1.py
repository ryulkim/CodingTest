a=(5,-5)
b=(-5,5)

if a[0]==b[0] and a[1]==b[1]:
    print("same points")
elif a[0]==b[0] and a[1]==-b[1]:
    print("X-axis symmetry")
elif a[0]==-b[0] and a[1]==b[1]:
    print("Y-axis symmetry")
elif a[0]==-b[0] and a[1]==-b[1]:
    print("origin symmetry")
else:
    print("Nothing")