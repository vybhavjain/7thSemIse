library(e1071)	#for naive Bayes classifier
library(caret)	#for confusionMatrix


data1<- read.csv("hospital.csv")

index<- sample(2, nrow(data1), TRUE, c(0.7,0.3))

train<- data1[index==1,]
test<- data1[index==2,]

features<- type ~cost

model1 <- naiveBayes(features,train)
print(model1)

print(test)
res1 <- predict(model1,test)

confusionMatrix(res1,test$type)

