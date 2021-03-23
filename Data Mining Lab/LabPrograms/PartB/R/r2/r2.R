data <- iris

summary(data)

head(data)
tail(data)

mean(data$Sepal.Length)
median(data$Sepal.Width)
range(data$Petal.Length)

var(data$Petal.Width)
quantile(data$Sepal.Length)

table(data$Species)

cov(data$Sepal.Length,data$Petal.Length)
cor(data$Sepal.Length,data$Petal.Length)

hist(data$Sepal.Length)
plot(density(data$Petal.Width))
pie(table(data$Species), main="Number of Species Pie-Chart")
barplot(table(data$Sepal.Length), xlab="Sepal Length", ylab="Frequency")
plot(data$Petal.Length)
