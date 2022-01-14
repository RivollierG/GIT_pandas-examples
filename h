[1mdiff --cc DataFrame_Groupby.py[m
[1mindex 0b9cab0,a0338f0..0000000[m
[1m--- a/DataFrame_Groupby.py[m
[1m+++ b/DataFrame_Groupby.py[m
[36m@@@ -1,5 -1,6 +1,10 @@@[m
  # -*- coding: utf-8 -*-[m
[32m++<<<<<<< HEAD[m
[32m +__author__ = 'V1cent'[m
[32m++=======[m
[32m+ [m
[32m+ __author__ = 'Guillaume'[m
[32m++>>>>>>> 420ee9d2b121e1cf5e529886c3f30b5c582feadf[m
  [m
  import pandas as pd[m
  import numpy as np[m
[36m@@@ -7,15 -8,27 +12,39 @@@[m
  # Load Data[m
  userHeader = ['user_id', 'gender', 'age', 'ocupation', 'zip'][m
  users = pd.read_csv('dataSet/users.txt', engine='python',[m
[32m++<<<<<<< HEAD[m
[32m +                    sep='::', header=None, names=userHeader, encoding='ISO-8859-1')[m
[32m +[m
[32m +movieHeader = ['movie_id', 'title', 'genders'][m
[32m +movies = pd.read_csv('dataSet/movies.txt', engine='python',[m
[32m +                     sep='::', header=None, names=movieHeader, encoding='ISO-8859-1')[m
[32m +[m
[32m +ratingHeader = ['user_id', 'movie_id', 'rating', 'timestamp'][m
[32m +ratings = pd.read_csv('dataSet/ratings.txt', engine='python',[m
[32m +                      sep='::', header=None, names=ratingHeader, encoding='ISO-8859-1')[m
[32m++=======[m
[32m+ <<<<<<< HEAD[m
[32m+                     sep='::', header=None, names=userHeader,encoding = "ISO-8859-1")[m
[32m+ [m
[32m+ movieHeader = ['movie_id', 'title', 'genders'][m
[32m+ movies = pd.read_csv('dataSet/movies.txt', engine='python',[m
[32m+                      sep='::', header=None, names=movieHeader,encoding =  "ISO-8859-1")[m
[32m+ [m
[32m+ ratingHeader = ['user_id', 'movie_id', 'rating', 'timestamp'][m
[32m+ ratings = pd.read_csv('dataSet/ratings.txt', engine='python',[m
[32m+                       sep='::', header=None, names=ratingHeader,encoding = "ISO-8859-1")[m
[32m+ =======[m
[32m+                     sep='::', header=None, names=userHeader, encoding='ISO-8859-1')[m
[32m+ [m
[32m+ movieHeader = ['movie_id', 'title', 'genders'][m
[32m+ movies = pd.read_csv('dataSet/movies.txt', engine='python',[m
[32m+                      sep='::', header=None, names=movieHeader, encoding='ISO-8859-1')[m
[32m+ [m
[32m+ ratingHeader = ['user_id', 'movie_id', 'rating', 'timestamp'][m
[32m+ ratings = pd.read_csv('dataSet/ratings.txt', engine='python',[m
[32m+                       sep='::', header=None, names=ratingHeader, encoding='ISO-8859-1')[m
[32m+ >>>>>>> ef3cd2ca0201da89d5b97232e243e9a434610e93[m
[32m++>>>>>>> 420ee9d2b121e1cf5e529886c3f30b5c582feadf[m
  [m
  # Merge data[m
  mergeRatings = pd.merge(pd.merge(users, ratings), movies)[m
[36m@@@ -24,7 -37,10 +53,14 @@@[m
  [m
  [m
  def cloneDF(df):[m
[32m++<<<<<<< HEAD[m
[32m +    return pd.DataFrame(df.values.copy(), df.index.copy(), df.columns.copy())[m
[32m++=======[m
[32m+ [m
[32m+     a = pd.DataFrame(df.values.copy(), df.index.copy(), df.columns.copy())[m
[32m+     return a.apply(pd.to_numeric, errors = 'ignore')[m
[32m+ [m
[32m++>>>>>>> 420ee9d2b121e1cf5e529886c3f30b5c582feadf[m
  [m
  [m
  # Show Films with more votes. (groupby + sorted)[m
[36m@@@ -50,16 -66,28 +86,43 @@@[m [mprint('Films ratings info: \n%s' % data[m
  print('\n==================================================================\n')[m
  [m
  [m
[32m++<<<<<<< HEAD[m
[32m +# Show data ratings movies, applying a function (groupby + lambda function)[m
[32m +myAvg = cloneDF(mergeRatings)[m
[32m +myAvg = myAvg.groupby(['movie_id', 'title'])['rating'].agg([m
[32m +    SUM=np.sum, COUNT=np.size, AVG= np.mean, myAVG= lambda x: x.sum() / float(x.count()))[m
[32m +print('My info ratings: \n%s' % myAvg[:10])[m
[32m +print('\n==================================================================\n')[m
[32m +[m
[32m +[m
[32m +# Sort data ratings by created field (groupby + lambda function + sorted)[m
[32m +sortRatingsField_V1cent = cloneDF(mergeRatings)[m
[32m +youpi = sortRatingsField.groupby(['movie_id', 'title'])['rating'].agg([m
[32m +    COUNT= np.size, myAVG=lambda x: x.sum() / float(x.count())).sort_values('COUNT', ascending=False)[m
[32m++=======[m
[32m+ [m
[32m+ # # Show data ratings movies, applying a function (groupby + lambda function)[m
[32m+ # myAvg = cloneDF(mergeRatings)[m
[32m+ # myAvg = myAvg.groupby(['movie_id', 'title'])['rating'].agg([m
[32m+ #     {'SUM': np.sum, 'COUNT': np.size, 'AVG': np.mean, 'myAVG': lambda x: x.sum() / float(x.count())})[m
[32m+ # print('My info ratings: \n%s' % myAvg[:10])[m
[32m+ # print('\n==================================================================\n')[m
[32m+ [m
[32m+ [m
[32m+ # Sort data ratings by created field (groupby + lambda function + sorted)[m
[32m+ sortRatingsField = cloneDF(mergeRatings)[m
[32m+ sortRatingsField = sortRatingsField.groupby(['movie_id', 'title'])['rating'].agg([m
[32m+    COUNT= np.size, myAVG= lambda x: x.sum() / float(x.count())).sort_values('COUNT', ascending=False)[m
[32m++>>>>>>> 420ee9d2b121e1cf5e529886c3f30b5c582feadf[m
  print('My info sorted: \n%s' % sortRatingsField[:15])[m
[32m+ [m
[32m+ [m
[32m+ [m
[32m+ [m
[32m+ [m
[32m+ # Sort data ratings by created field (groupby + lambda function + sorted)[m
[32m+ ratingsFieldSort = cloneDF(mergeRatings)[m
[32m+ ratingsFieldSort = ratingsFieldSort.groupby(['movie_id', 'title'])['rating'].agg([m
[32m+     COUNT=np.size, myAVG=lambda x: x.sum() / float(x.count())).sort_values('COUNT', ascending=False)[m
[32m+ print('My info sorted: \n%s' % ratingsFieldSort[:15])[m
[32m+ [m
