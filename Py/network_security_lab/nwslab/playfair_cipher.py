# -*- coding: utf-8 -*-
"""
Created on Wed Jan 13 23:12:18 2016

@author: ramashish
"""

import numpy as np
import matplotlib.pyplot as plt

#pt = str(raw_input('Enter the plaintext: ')) #Receive input from console
pt = open(r'text_file.txt').read() # Receive input from text file
ct = ''

key = str(raw_input('Enter your key (upper case,number of unique letters less than 26): ')) 

key_mat = [['' for x in range(5)] for x in range(5)]
key = key.replace(' ','')

# Remove the repeated letters in key and store the letters in row order

new_key = []
for char in key:
    if char not in new_key:
        new_key.append(char)
 
i=0
j=0

rest_chars = [chr(x) for x in range(65,91)]


for char in new_key:
    rest_chars.remove(char)

rest_chars.remove('Q')
    
new_key = new_key + rest_chars

for char in new_key:
    key_mat[i][j]=char
    j+=1
    if(j==5):
        i+=1
        j=0

print 'Key Matrix :', key_mat

## Encryption begins
if(len(pt)%2==1): # Make the length of plain_text even
    pt+='z'
    
def get_position(char):
    for i in range(5):
        for j in range(5):
            if(key_mat[i][j]==char):
                return (i,j)
    
    return(4,4) # If Q occurs in the plain_text
    
for i in range(0,len(pt),2):
    char1 = pt[i].upper()
    char2 = pt[i+1].upper()
    
    # Get the position of characters in key_mat
    pos1 = get_position(char1) 
    pos2 = get_position(char2)
    
    if(pos1[0]== pos2[0]): # Same Row
        col1 = (pos1[1]+1)%5
        col2 = (pos2[1]+1)%5
        en_char1 = key_mat[pos1[0]][col1]
        en_char2 = key_mat[pos1[0]][col2]
        ct+=(en_char1+en_char2)
    elif(pos1[1]==pos2[1]): # Same Column
        row1 = (pos1[0]+1)%5
        row2 = (pos2[0]+1)%5
        en_char1 = key_mat[row1][pos1[1]]
        en_char2 = key_mat[row2][pos1[1]]
        ct+=(en_char1+en_char2)
    else:
        en_char1 = key_mat[pos1[0]][pos2[1]]
        en_char2 = key_mat[pos2[0]][pos1[1]]
        ct+=(en_char1+en_char2)

print 'PlayFair Encrypted text :',ct

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