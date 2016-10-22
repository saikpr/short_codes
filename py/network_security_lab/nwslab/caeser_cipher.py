# -*- coding: utf-8 -*-
"""
Caeser Cipher : Encryption.

@author: ramashish
"""
import numpy as np
import matplotlib.pyplot as plt
pt = str(raw_input('Enter the plaintext: ')) #Receive input from console
#pt = open(r'text_file.txt').read() # Receive input from text file



shift = 3
ct = ''

# Enciphering the plain_text
for char in pt:
    if (ord(char.lower())>=97) & (ord(char.lower())<=122):
        ct+=chr((ord(char.lower())-97+shift)%26 + 97).upper()
    else:
        ct+=char
        
# Deciphering the cipher_text

new_pt=''
for char in ct:
    if(ord(char.lower())>=97) & (ord(char.lower())<=122):
        new_pt+=chr((ord(char.lower())-97-shift)%26+97).lower()
    else:
        new_pt+=char

print 'Decrypted Cipher Text :',new_pt
    

print 'Caeser - Encrypted text: ',ct

### Creating a frequency table ####

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

############ Creating a frequency table for plain_text ##########
chars = [(chr(i),chr(i).upper()) for i in range(97,123)]
freq = [0 for x in range(26)]
for char in new_pt:
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

    
#print chr((ord(pt)-97+3)%26 + 97)