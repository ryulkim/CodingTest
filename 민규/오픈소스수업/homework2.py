import os
import pandas as pd
from mxnet import gluon, np
from d2l import mxnet as d2l

##########################################3

d2l.DATA_HUB['ml-100k'] = (
    'http://files.grouplens.org/datasets/movielens/ml-100k.zip',
    'cd4dcac4241c8a4ad7badc7ca635da8a69dddb83')

def read_data_ml100k():
    data_dir = d2l.download_extract('ml-100k')
    names = ['user_id', 'movie_id', 'rating', 'timestamp']
    data = pd.read_csv(os.path.join(data_dir, 'u.data'), '\t', names=names,
                       engine='python')
    
    names2 = ['user_id', 'age', 'sex','job', 'code']
    user = pd.read_csv(os.path.join(data_dir, 'u.user'), '|', names=names2,
                       engine='python')
    
    names3 = ['movie_id', 'movie_name' ,'release date','video release date', 'IMDb URL', 'unknown', 'Action', 'Adventure',
'Animation', 'Children\'s', 'Comedy', 'Crime', 'Documentary', 'Drama', 'Fantasy',
'Film-Noir', 'Horror', 'Musical', 'Mystery', 'Romance', 'Sci-Fi', 'Thriller', 'War', 'Western']
    item = pd.read_csv(os.path.join(data_dir, 'u.item'), '|',names=names3,
        encoding = "ISO-8859-1", engine='python')
    
    return data,user,item

#############################################33

data, user,item = read_data_ml100k()

quiz0 = pd.merge(data, item)
quiz0 = pd.merge(quiz0, user)

female0 = quiz0[quiz0['sex'] == 'F']
male0 = quiz0[quiz0['sex'] == 'M']


job_list = quiz0["job"].unique()

########################################## lambda x:x.value_counts().index[0]}).reset_index()

group1 = quiz0.groupby('movie_name')['rating'].agg(**{ 'count' : 'count' , 'mean' : 'mean' , 'many': 'max'}).reset_index()
group1 = group1.sort_values(['count'] , ascending = False)
group1 = group1.head(100)

all_user1= group1.sort_values(['many'] , ascending = False)
print("all user + highest number(2_a)\n")
print(all_user1[['movie_name' , 'many']])
print("\n")

all_user1= group1.sort_values(['mean'] , ascending = False)
print("all user + highest average(2_b)\n")
print(all_user1[['movie_name' , 'mean']])

#####################################################3
 
group1 = female0.groupby('movie_name')['rating'].agg(**{ 'count' : 'count' , 'mean' : 'mean' , 'many': 'max'}).reset_index()
group1 = group1.sort_values(['count'] , ascending = False)
group1 = group1.head(100)


all_user1= group1.sort_values(['many'] , ascending = False)
print("female + highest number(2_a)\n")
print(all_user1[['movie_name' , 'many']])
print("\n")

all_user1= group1.sort_values(['mean'] , ascending = False)
print("female + highest average(2_b)\n")
print(all_user1[['movie_name' , 'mean']])

##########################################33

group1 = male0.groupby('movie_name')['rating'].agg(**{ 'count' : 'count' , 'mean' : 'mean' , 'many': 'max'}).reset_index()
group1 = group1.sort_values(['count'] , ascending = False)
group1 = group1.head(100)

all_user1= group1.sort_values(['many'] , ascending = False)
print("male + highest number(2_a)\n")
print(all_user1[['movie_name' , 'many']])
print("\n")

all_user1= group1.sort_values(['mean'] , ascending = False)
print("male + highest average(2_b)\n")
print(all_user1[['movie_name' , 'mean']])

####################################3

for name in job_list:
 quiz01 = quiz0[quiz0['job'] == name]
 group1 = quiz01.groupby('movie_name')['rating'].agg(**{ 'count' : 'count' , 'mean' : 'mean' , 'many': 'max'}).reset_index()
 group1 = group1.sort_values(['count'] , ascending = False)
 group1 = group1.head(100)
 
 all_user1= group1.sort_values(['many'] , ascending = False)
 print(name  + " highest number(2_a)\n")
 print(all_user1[['movie_name' , 'many']])
 print("\n")
    
 all_user1= group1.sort_values(['mean'] , ascending = False)
 print(name + " highest average(2_b)\n")
 print(all_user1[['movie_name' , 'mean']])

##########################3














