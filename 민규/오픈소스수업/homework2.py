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


data2 = data[data['rating'] > 4]

quiz1 = pd.merge(data2, item)
quiz1 = pd.merge(quiz1, user) 
#print("highest number of ratings :  for all user\n")
#print(quiz1['movie_name'].head(20))

quiz01 = quiz1
quiz01.drop_duplicates(['movie_id'], keep = 'first')

female1 = quiz1[quiz1['sex'] == 'F']
female1.drop_duplicates(['movie_id'], keep = 'first')

male1 = quiz1[quiz1['sex'] == 'M']
male1.drop_duplicates(['movie_id'], keep = 'first')

job_list = quiz1["job"].unique()

##########################################

print("highest number of ratings(all user) :  for all user\n")
print(quiz01['movie_name'].head())

#####################################################3
 
print("highest number of ratings(female) :  for all sex\n")
print(female1['movie_name'].head())

##########################################33

print("highest number of ratings(male) :  for all sex\n")
print(male1['movie_name'].head())

####################################3

for name in job_list:
 quiz02 = quiz1[quiz1['job'] == name]
 quiz02.drop_duplicates(['movie_id'], keep = 'first')
 print("highest number of ratings(" name + ") :in all job \n")
 print(quiz02['movie_name'].head(5) + "\n")

######################################3











