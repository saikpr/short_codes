# -*- coding: utf-8 -*-
"""
Created on Thu Jan 14 14:01:50 2016

@author: shashi
"""

import numpy as np
import matplotlib.pyplot as plt

pt = str(raw_input('Enter the plain text(in lower case):  '))
#pt = open(r'text_file.txt').read()
pt.replace(' ','')

# Key matrix > n x n
key_mat = [[2,3,1],
           [1,2,4],
           [2,2,4]]
        
key_mat = np.matrix(key_mat)

length = len(pt)
if(length%3==1):
    pt+='zz'
    length+=2
elif(length%3==2):
    pt+='z'
    length+=1


ct=''
for i in range(0,length,3):
    char1 = (ord(pt[i].lower())-97)%26
    char2 = (ord(pt[i+1].lower())-97)%26
    char3 = (ord(pt[i+2].lower())-97)%26
    char_mat = np.matrix([char1,char2,char3])
    char_mat = char_mat.transpose()
    
    cipher_mat = np.dot(key_mat,char_mat)%26
    for j in range(3):
        ct+=chr(cipher_mat[j,0]+65)


#print 'Hill Cipher Encrypted text: ',ct

### Creating a frequency table for cipher_text ####

chars = [chr(i) for i in range(65,91)]
freq = [0 for x in range(26)]
for char in ct:
    if(char >='A' and char <='Z'):
        freq[ord(char)-65]+=1
    
pos = np.arange(len(chars))
width = 0.5
ax = plt.axes()
ax.set_xticks(pos + (width / 2))
ax.set_xticklabels(chars)

plt.bar(pos, freq, width, color='r')
plt.show()
############# Frequency histogram made ##############

############# Creating a frequency table for plain_text ##########
chars = [chr(i) for i in range(97,123)]
freq = [0 for x in range(26)]
for char in pt:
    if(char >= 'a' and char <='z'):
        freq[ord(char)-97]+=1

pos = np.arange(len(chars))
width=0.5
ax=plt.axes()
ax.set_xticks(pos+(width/2))
ax.set_xticklabels(chars)

plt.bar(pos,freq,width,color = 'g')
plt.show()

########## Bar plot made #################
