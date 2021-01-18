library("MASS")
library("survival")
library("ipred")

data("BreastCancer", package = "mlbench")
mod <- bagging(Class ~ Cl.thickness + Cell.size
               + Cell.shape + Marg.adhesion   
               + Epith.c.size + Bare.nuclei   
               + Bl.cromatin + Normal.nucleoli
               + Mitoses, data=BreastCancer, coob=TRUE)
print(mod)

data("Ionosphere", package = "mlbench")
Ionosphere$V2 <- NULL # constant within groups

bagging(Class ~ ., data=Ionosphere, coob=TRUE)

comb.lda <- list(list(model=lda, predict=function(obj, newdata)
  predict(obj, newdata)$x))

mod <- bagging(Class ~ ., data=Ionosphere, comb=comb.lda) 

predict(mod, Ionosphere[1:10,])
data("BostonHousing", package = "mlbench")

mod <- bagging(medv ~ ., data=BostonHousing, coob=TRUE)
print(mod)

library("mlbench")
learn <- as.data.frame(mlbench.friedman1(200))

mod <- bagging(y ~ ., data=learn, coob=TRUE)
print(mod)

data("DLBCL", package = "ipred")
mod <- bagging(Surv(time,cens) ~ MGEc.1 + MGEc.2 + MGEc.3 + MGEc.4 + MGEc.5 +
                 MGEc.6 + MGEc.7 + MGEc.8 + MGEc.9 +
                 MGEc.10 + IPI, data=DLBCL, coob=TRUE)

print(mod)
