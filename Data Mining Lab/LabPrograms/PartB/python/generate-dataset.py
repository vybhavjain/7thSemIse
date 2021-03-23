# file to create a random dataset (& save time)
from sklearn.datasets import make_classification
import pandas as pd

X,y = make_classification(n_samples=50, n_features=10)
data = pd.DataFrame(X,y)
data.to_csv('dataset.csv')

# Please edit the csv file just after to include column names to make the later steps easier
# You can also use excel/libre office shortcuts to make stuff easier
