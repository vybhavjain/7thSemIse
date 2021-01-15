library(rpart)	#for decision tree1
library(rpart.plot)	#graph for decision tree1
library(e1071)	#for naive Bayes classifier
library(party)	#for decision tree2
library(caret)	#for confusionMatrix

data <- iris

index <- sample(2,nrow(data),replace=TRUE,p=c(0.7,0.3))
trainData <- data[index==1,]
testData <- data[index==2,]

features <- Species ~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width
tree1 <- rpart(features,trainData,method="class")
rpart.plot(tree1)

tree2 <- ctree(features,trainData)
plot(tree2)

res1 <- predict(tree2,testData)
confusionMatrix(res1,testData$Species)

model1 <- naiveBayes(features,trainData)
print(model1)

res2 <- predict(model1,testData)
confusionMatrix(res2,testData$Species)
