#reading from CSV file
data1 <- read.csv('diabetes.csv')	

#library for fviz_cluster
library(factoextra)

hModel <- hclust(dist(data1[,2:2],method="euclidian"))
plot(hModel)
