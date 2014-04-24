list1=[]
k=raw_input()
n=len(k)
from operator import itemgetter

def ifpalin(str1,i,j):
	even=False
	ini=i
	inj=j
	if (i==j):
		return False
	if (j-i)%2==1:
		even=True
	else:
		even=False
	
	if even==True:
		while i +1 != j:
			if str1[i] != str1[j]:
				return False
			i=i+1
			j=j-1
		if str1[i] != str1[j]:
				return False

		
	if even==False:
		try:
			while i != j:
				if str1[i] != str1[j]:
					return False
				i=i+1
				j=j-1
		except IndexError:
			print i,j,even,ini,inj
	return True
if __name__ == '__main__':
	for i in xrange(n):
		for j in xrange(n):
			if i<=j:
				if ifpalin(k,i,j)==True:
					#print k[i:j+1]

					test=[len(k[i:j+1])]
					test.append(k[i:j+1])
					test.append([i,j])
					#print test
					list1.append(test)
	# list1
	listasc=sorted(list1, key=itemgetter(0))
	listdes=sorted(list1,key=itemgetter(0),reverse=True)
	minlen=listasc[0][0]
	maxlen=listdes[0][0]
	maxli1=[]
	print "Largest Palindromes of length "  +str(maxlen)
	for li in listdes:
		if li[0]==maxlen:
			print li[1]
			maxli1.append(li)

	
	trige1=True
	for li in listasc:
		for lim in maxli1:
			if li[1] not in lim[1]:
				if trige1==True:
					trige1=False
					print "Smallest Palindromes of length : " + str(li[0])
					minlen=li[0]
				if li[0]==minlen:
					print li[1]
	if trige1==True:
		print "I am unable to find mutually exculsive smallest palindromes"

	
