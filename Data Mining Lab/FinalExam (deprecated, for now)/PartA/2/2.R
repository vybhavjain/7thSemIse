library(party)
library(caret)

data1<- read.csv("fever.csv")

index<- sample(2, nrow(data1), TRUE, c(0.7,0.3))

train<- data1[index==1,]
test<- data1[index==2,]

#Y~x
features<- Result~i1+i3+i2+i4

model <- ctree(features, data=train)

plot(model)

print(test)
res1 <- predict(model,test)
confusionMatrix(res1,test$Result)