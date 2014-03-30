i=0
file3=open('contestdata_0.txt')
for cont in file3.readlines():
	i=i+1
	if i<100:
		print str(cont)
	if i%10000==0:
		print i
print i