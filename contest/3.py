num=int(raw_input())

a=11
b=18
thisnum=0
for i in xrange(2,num):
	thisnum=a+b
	b=a
	a=thisnum
k=a*971-1571*b
print k
