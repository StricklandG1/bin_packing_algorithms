import matplotlib
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import linregress

df1 = pd.read_csv("next_fit.txt",header = None, usecols=[1,2],names=['runs','waste'])

slope,intercept,r_value,p_value,std_err = linregress(df1.runs,df1.waste)

plt.loglog(df1.runs, df1.waste,'k.')
plt.xlabel('N')
plt.ylabel('Waste')
plt.show
