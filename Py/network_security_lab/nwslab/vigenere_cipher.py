# -*- coding: utf-8 -*-
"""
Created on Wed Jan 13 22:43:27 2016

@author: ramashish
"""

import numpy as np
import matplotlib.pyplot as plt
from itertools import cycle
pt = str(raw_input('Enter the plaintext: ')) #Receive input from console
#pt = open(r'text_file.txt').read() # Receive input from text file
ct = ''

key = str(raw_input('Enter your key (small case): ')) 

pairs = zip(pt.lower(),cycle(key)) # First character in tuple is plain_text and second
                           # character is cipher_text

for pair in pairs:
    ct += chr((ord(pair[0])-97+ord(pair[1])-97)%26+65)

print 'Vigenere Encrypted text : ',ct

### Decryption ##############

new_pt = ''
dcrpt_pairs = zip(ct,cycle(key))

for pair in dcrpt_pairs:
    new_pt += chr((ord(pair[0])-65-ord(pair[1]))%26)

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