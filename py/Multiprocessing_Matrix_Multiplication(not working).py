from __future__ import print_function
from time import time
from random import randint
import multiprocessing 

class matrixProcess(multiprocessing.Process):
     def __init__(self,mat1,mat2,row,colm,size):
         multiprocessing.Process.__init__(self)
         self.colm=colm
         self.row=row
         self.size=size
         self.sum=0
     def run(self):
         for i in range(self.size):
             self.sum+=mat1[i][self.colm] * mat2[self.row][i]
             
size=int(raw_input("Enter the order of matrixies to be multiplied :"))
ans=raw_input("If you want to use random instead of entering(y or n) :")
mat3 = [[0 for x in xrange(size)] for x in xrange(size)]
mat4 = [[0 for x in xrange(size)] for x in xrange(size)]
ans=ans.lower()
if ans == 'y' or ans == 'yes':
	mini,maxi=raw_input("Enter the min and max value :").split()
	maxi=int(maxi)
	mini=int(mini)
	mat1 = [[randint(mini,maxi) for x in xrange(size)] for x in xrange(size)]
	mat2 = [[randint(mini,maxi) for x in xrange(size)] for x in xrange(size)]
else:
	mat1 = [[0 for x in xrange(size)] for x in xrange(size)]
	mat2 = [[0 for x in xrange(size)] for x in xrange(size)]
	for i in xrange(size):
		mat1[i]=raw_input().split()
	print ("Now Enter Second MAT")
	for j in xrange(size):
		mat2[j]=raw_input().split()
for i in xrange(size):
	for j in xrange(size):
		mat1[i][j]=int(mat1[i][j])
		mat2[i][j]=int(mat2[i][j])
array = []
for i in xrange(size*size):
	array.append(matrixProcess(mat1,mat2,int(i/size),i%size,size))
processingtime=time()

for process in array:
	process.start()
for process in array:
	process.join()  # This waits until the process has completed
	mat3[process.row][process.colm]=int(process.sum)
processingtime=time()-processingtime
normaltime=time()
for i in xrange(size):
	for j in xrange(size):
		var_sum=0
		for k in xrange(size):
			var_sum+=mat1[k][j] * mat2[i][k]
		mat4[i][j]=var_sum
normaltime=time()-normaltime
ans=raw_input("Want to print the resultant array :")
ans=ans.lower()
if ans=='y/r' or ans=='yes/r':
	print('The Resultant matrix is(using processing)')
	for i in xrange(size):
		for j in xrange(size):
			print (mat3[i][j], end=" ")
		print('')
	print('The Resultant matrix is(without processing)')
	for i in xrange(size):
		for j in xrange(size):
			print (mat4[i][j], end=" ")
		print('')
print("Time taken for processing with processs 	  :"+str(processingtime))
print("Time taken for processing without processs :"+str(normaltime))
