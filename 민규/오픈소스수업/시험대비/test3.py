import pandas as pd
from pandas import Series, DataFrame

obj = pd.Series([4,7,-5,3], index=['a','b'])
obj.values

obj[obj2 > 0]
obj.rank(ascending = False)

#dicitionary 관련
data = {'a' : [] , 'b' : []}
frame = DataFrame(data,columns = ['h', 'e'], index = ['d' ,'e'])
frame.loc('d')

#frame2['eastern'] = frame2.state = 'dd'






