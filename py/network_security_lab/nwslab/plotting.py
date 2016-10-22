# -*- coding: utf-8 -*-
"""
Created on Fri Feb 05 11:27:39 2016

@author: ramashish
"""

import matplotlib.pyplot as plt
x = [1600,5000,7500,10000,15000]
y_old = [13.33, 23.06, 26.44, 27.63, 30.16]
y_new = [16.83, 24.40, 27.53, 29.05, 31.70]

plt.plot(x,y_old, 'rs', x, y_new, 'go')
plt.legend(['Unsupervised MF', 'Supervised MF'], loc='upper-left')
plt.show()