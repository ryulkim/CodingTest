import matplotlib.pyplot as plt

#data = np.arange(15)

#np.sqrt(data) # 루트 씌운 값
#np.exp(data) #e^x 꼴

#x = np.random.randn(4) * 5
#y = np.random.randn(4)

#np.maximum(x,y)


#x1,x2 = np.modf(x) #정수부 소수부 분리

#x1 #소수부분 
#x2 #정수부분



#x = np.arange(2,5,0.01) #0.01씩 커지는 aragne를 만든다
#x1, y1 = np.meshgrid(x,x) # x,y축 분리

#z = np.sqrt(x1**2 + y1**2) # 거리 계산
#plt.imshow(z, cmap = plt.cm.gray); plt.colorbar() #plt로 모양을 나타내는 다양한 방법

#xarr = np.array([1,2,3,4,5])
#yarr = np.array([1.1,2.1,3.1,4.1,5.1])
#cond = np.array([True, False, False , False, False])
 
#result = [(x if c else y) for x,y,c in zip(xarr, yarr,cond )] #만약에 C면 X 아니면 Y
#result = np.where(cond, xarr, yarr)
#result

arr = np.random.randn(4,4)

#np.where(arr > 0, 1 , arr) #where은 보여주기 까지한다, mask를 제대로 씌울 수 있음

#arr.mean()
#arr.sum(axis)

#arr = np.arange(32).reshape(4,8)

#(arr > 0).sum()

#arr.any()
#arr.all()

#arr.sort(1)
#arr


nsteps = 1000
draws = np.random.randint(0,2, size = nsteps)
steps = np.where(draws > 0, 1 , -1)
walk = steps.cumsum()

#plt.plot(walk) #이거 시험에 나올 가능성 있음


#print(walk.max())
#(np.abs(walk) >= 10).argmax()







