library(factoextra)

data <- iris
data$Species <- NULL

distance1 <- scale(dist(data,method="euclidian"))
kModel <- kmeans(distance1,3)
fviz_cluster(kModel, data, geom="point")

distance2 <- dist(data[,3:4],method="euclidian")
hModel <- hclust(distance2,method="average")
plot(hModel)