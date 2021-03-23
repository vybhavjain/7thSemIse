#loading the data
data1 <- read.csv('climate.csv')	

temp<- data1$avg_temp
temp_uncert <- data1$avg_temp_uncertain
 
#Y vs X
features <-  temp_uncert~ temp  # Y~X

#create the linear model
linearModel <- lm(features,data1)

#plot the linear model
plot(features)
abline(linearModel)

#predict value for some given data
test <- data.frame(temp=c(24))
predValue <- predict(linearModel,test)
print(predValue)
