library(arules)
library(arulesViz)

Groceries <- read.csv("Groceries.csv")
data(Groceries)

inspect(Groceries[1:10])

itemFrequencyPlot(Groceries,topN=10,type="absolute")

itemSets <- apriori(Groceries, parameter=list(minlen=1, maxlen=10,sup=0.02, target="frequent itemsets"))
inspect(sort(itemSets,by="support"))

itemRules <- apriori(Groceries, parameter=list(minlen=1, maxlen=10, sup=0.02, conf=0.4, target="rules"))
inspect(sort(itemRules,by="confidence"))

plot(itemRules, method="graph")
