# -*- coding: utf-8 -*-
"""
Created on Thu Feb 25 00:29:43 2016

@author: zerone
"""

import base64

# RC4 implementation
def rc4_crypt(data,key):
    S = range(256) # Define an array S in which entries are later swapped
    key_length = len(key)
    
    
    # Key Schedule Phase
    j = 0
    for i in range(256):
        j = (j+S[i]+ord(key[i%key_length]))%256
        S[i], S[j] = S[j], S[i]
        
    # Pseudo Random Generation Algorithm  
    
    i=j=0
    out = []
    for char in data:
        i = (i+1)%256
        j = (j+S[i])%256
        
        S[i],S[j] = S[j],S[i]
        out.append(chr(ord(char) ^ S[(S[i] + S[j])%256]))
    
    return ''.join(out)
    

def encrypt(data,key,encode = base64.b64encode):
    data = rc4_crypt(data,key)
    if encode:
        data = encode(data)
    
    return data

def decrypt(data,key, decode = base64.b64decode):
    
    if decode:
        data = decode(data)
    
    return rc4_crypt(data,key)

def main():
    
    data = str(raw_input('Enter the message: '))
    key = str(raw_input('Enter the key: '))
    
    data = encrypt(data,key)
    
    print 'Encrypted message: ', data
    
    data = decrypt(data,key)
    
    print 'Decrypted message: ', data
    
    return 0

if __name__ == '__main__':
    main()
    