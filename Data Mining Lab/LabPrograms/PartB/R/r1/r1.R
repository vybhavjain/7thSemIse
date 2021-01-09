#install.packages("dplyr")

min_max_norm <- function(x) {
  (x - min(x)) / (max(x) - min(x))
}
library(dplyr)
library(arules)
# read csv
melanoma <- read.csv("melanoma.csv")
View(melanoma)
melanoma
# handle missing values
is.na(melanoma$time) # returns true for na, false otherwise
list_na = colnames(melanoma)[apply(melanoma,2,anyNA)] # list of column names with na
list_na
# exclude missing values
melanoma_drop <- melanoma %>%
na.omit()
# after removing missing values
dim(melanoma_drop)
#find average of all the values excluding the missing values stored in list_na
average_missing <- apply(melanoma[,colnames(melanoma) %in% list_na],
                         2,
                         mean,
                         na.rm =  TRUE)
average_missing
#replace(impute) missing values for 4 attributes where average value is stored in average_missing
melanoma_replace <- melanoma %>% mutate(replace_mean_time  = ifelse(is.na(time), average_missing[1], time),
         replace_mean_sex = ifelse(is.na(sex), average_missing[2], sex),
         replace_mean_age = ifelse(is.na(age),average_missing[3], age),
         replace_mean_thick = ifelse(is.na(thickness),average_missing[4],thickness))
head(melanoma_replace)
#normalize the replace_mean_thick attribute
summary(melanoma_replace$replace_mean_thick) # gives summary of replace_mean_thick attribute
log_thick = log(melanoma_replace$replace_mean_thick)
summary(log_thick)
# correlation between time and thickness which does not have a NA attribute
cor(melanoma_replace$replace_mean_time,melanoma_replace$replace_mean_thick)
#delete column
melanoma_replace
melanoma_replace[c(1,2,4,5,7)]<-list(NULL)
melanoma_replace
correl_dat <- cor(melanoma_replace[,c(1,2,3,4,5,6,7)])
correl_dat
#using min-max normalization
mela_norm <- as.data.frame(lapply(melanoma_replace[4:7], min_max_norm))
head(mela_norm)
mela_norm$status <- melanoma_replace$status
mela_norm$year <-melanoma_replace$year
mela_norm$ulcer <-melanoma_replace$ulcer
head(mela_norm)
# similiarly u can perform either z-transformation

melaDisc <- discretizeDF(mela_norm, methods = list(
  replace_mean_thick = list(method = "frequency", breaks = 3, 
                      labels = c("short", "medium", "long")),
  replace_mean_time = list(method = "frequency", breaks = 2, 
                     labels = c("narrow", "wide"))
),
default = list(method = "none")
)
head(melaDisc)
