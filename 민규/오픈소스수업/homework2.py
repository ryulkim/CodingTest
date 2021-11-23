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

##########################################

group1 = quiz0['rating'].groupby(quiz0['movie_name']).agg(['count', 'mean'])
group1 = group1.sort_values(['count'] , ascending = False).head(100)
all_user1= group1.sort_values(['mean'] , ascending = False)
print(all_user1['mean'])

#####################################################3
 
group1_f = female0['rating'].groupby(female0['movie_name']).agg(['count', 'mean'])
group1_f = group1_f.sort_values(['count'] , ascending = False).head(100)
all_female1= group1_f.sort_values(['mean'] , ascending = False)
print(all_female1['mean'])

##########################################33

group1_m = male0['rating'].groupby(male0['movie_name']).agg(['count', 'mean'])
group1_m = group1_m.sort_values(['count'] , ascending = False).head(100)
all_male1= group1_m.sort_values(['mean'] , ascending = False)
print(all_male1['mean'])

####################################3

for name in job_list:
 quiz01 = quiz1[quiz1['job'] == name]
 quiz01.drop_duplicates(['movie_id'], keep = 'first')
 print("highest number of ratings(" + name + ") :in all job \n")
 print(quiz01['movie_name'].head(7) + "\n")

######################################3

group1 = quiz0['user_id'].groupby(quiz0['rating'])
print(
print(group1.count())

##########################3














