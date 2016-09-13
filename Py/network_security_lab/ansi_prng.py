import struct
from pyDes import *

def accept_64bit_inputs():
    dt = str(raw_input('Enter seed value (64bit): '))
    iv = str(raw_input('Enter initialization vector (numeric value, 64bit): '))
    k1 = str(raw_input('Enter alphanumeric key1 (64bit): '))
    k2 = str(raw_input('Enter alphanumeric key2 (64bit): '))
    return dt,iv,k1,k2

def prng(n):
    dt,iv,k1,k2 = accept_64bit_inputs()
    tdes = triple_des(str(k1)+str(k2), padmode = PAD_PKCS5)
    
    for i in xrange(n):
        ct1 = tdes.encrypt(dt)
        
        pt1 = ''
        j=0
        for ch in ct1:
            pt1+=chr(ord(ch) ^ ord(iv[j%8]))
            j+=1
        
        ct2 = tdes.encrypt(pt1)
        
        print 'Random Number', i, ' : ', int(ct2.encode('hex'), 16)

        
        pt2=''
        j=0
        for ch in ct1:
            pt2+=chr(ord(ch) ^ ord(ct2[j%8]))
            j+=1
        
        ct3 = tdes.encrypt(pt2)
        
        iv = ct3
    

if __name__ == '__main__':
    n = int(raw_input('Enter the number of random numbers you want: '))
    prng(n)


        