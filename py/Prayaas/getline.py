i=0
from time import time
t=time() 
with open('contestdata_0.txt','rb') as f:

	for cont in f:
		i=i+1
t=time()-t
print str(type(cont)) +'\n'+str(i) +'\n'+ str(t)