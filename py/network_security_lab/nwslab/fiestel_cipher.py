# -*- coding: utf-8 -*-
"""
Created on Wed Feb 03 21:41:28 2016

@author: ramashish

Fiestel Cipher 

Subkey size = 5, Plaintext size = 10
"""


def accept_values():
    rounds = int(raw_input('Enter the number of rounds:'))
    keys = []
    print 'Enter %d subkeys each of length 5' % rounds
    for i in range(rounds):
        key = str(raw_input('Enter key %d' %(i+1)))
        keys.append(key)
    return rounds,keys
    

def string_xor(s1,s2):
    return(''.join(chr(ord(a) ^ ord(b)) for a,b in zip(s1,s2)))
    
    
def round_function(string,key):
    return(string_xor(string,key))
    

def encrypt(pt,rounds,keys):

    left = pt[:5]
    right = pt[5:10]
    
    for i in range(rounds):
        next_left = right
        next_right = string_xor(left,round_function(right,keys[i]))
        
        left = next_left
        right = next_right
    
    return right+left

def decrypt(ct,rounds,keys):
    
    right = ct[:5]
    left = ct[5:10]
    
    reversed_keys = list(reversed(keys))
    for i in range(rounds):
        next_right = left
        next_left = string_xor(right,round_function(left,reversed_keys[i]))
        
        left = next_left
        right = next_right
    
    return left+right
    

def fiestel(rounds,keys):
    
    pt = str(raw_input('Enter plaintext of length 10 :'))
    ct = encrypt(pt,rounds,keys)
    print 'After encryption cipher text is', ct
    print 'After decryption plaintext is', decrypt(ct,rounds,keys)
 
        
if __name__ == '__main__':
    rounds,keys = accept_values()
    fiestel(rounds,keys)
   
        