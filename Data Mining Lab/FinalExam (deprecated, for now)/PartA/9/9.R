#reading from CSV file
data1 <- read.csv('ratings.csv')	

#library for fviz_cluster
library(factoextra)

#K-Means Clustering
kModel <- kmeans(data1[,3:3],3)
fviz_cluster(kModel, data1)

