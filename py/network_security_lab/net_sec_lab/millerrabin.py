import random
import math
import sys

def rabinMiller(n):
     s = n-1
     t = 0
     while s&1 == 0:
         s = s/2
         t +=1
     k = 0
     while k<1:
         a = random.randrange(2,n-1)
         print a
         #a^s is computationally infeasible.  we need a more intelligent approach
         #v = (a**s)%n
         #python's core math module can do modular exponentiation
         v = pow(a,s,n) #where values are (num,exp,mod)
         if v != 1:
             i=0
             while v != (n-1):
                 if i == t-1:
                     return False
                 else:
                     i = i+1
                     v = (v**2)%n
         k+=2
     return True



if __name__=="__main__":
    # # print generateLargePrime(1024)
    # p= generateLargePrime(128)
    # q= generateLargePrime(128)
    print rabinMiller(29)
    print rabinMiller(221)
