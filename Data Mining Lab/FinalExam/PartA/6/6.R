#reading from CSV file
data1 <- read.csv('iris.csv')	

num_attributes <-(ncol(data1))
num_records <-(nrow(data1))

print(num_attributes)
print(num_records)

tail(data1, 10)
