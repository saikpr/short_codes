import random
import math
import sys

# Iterative Algorithm (xgcd)
def iterative_egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q,r = b//a,b%a; m,n = x-u*q,y-v*q # use x//y for floor "floor division"
        b,a, x,y, u,v = a,r, u,v, m,n
    return b, x, y

 
egcd = iterative_egcd  # or recursive_egcd(a, m)
 
def modinv(a, m):
    g, x, y = egcd(a, m) 
    if g != 1:
        return None
    else:
        return x % m


def rsa(p, q, e, M):
    n = int(p)*int(q)
    phi = (p-1)*(q-1)

    d = modinv(e, phi)
    print e,d, e*d%phi

    C = pow(M,e,n)

    print "Cipher Text is :" + str(C)

    d_M = pow(C,d,n)

    print "Decrypted value is :" + str(d_M)

if __name__=="__main__":
    rsa (17,11,7,88)
    rsa (11, 7 ,11 ,7)