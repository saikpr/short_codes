import math

def fast_exp(a,b,m):
	k = math.log(b,2)
	k= int(math.ceil(k))
	# print k
	c = 0
	f = 1

	for i in xrange (k,-1,-1):
		c = 2*c
		f = (f*f)%m

		if b & pow(2,i) >0:
			c = c+1
			f = (f*a)%m
	return f



def int_to_binary(b):
	k = int(math.ceil(math.log(b,2)))+1

	binary_str=""
	for i in xrange (k,0,-1):
		print b, pow(2,i-1)
		if b & pow(2,i-1) >0:
			binary_str+='1'
			print 1
		else:
			binary_str+='0'
			print 0
	return binary_str


if __name__ == "__main__":
	# print int_to_binary(560)
	print fast_exp(7,560,561)
	# print fast_exp(13,(10**9+7),10**9+7)
	# print pow(7,560,561)

	for i in xrange(1,10):
		for j in xrange(1,10):
			print fast_exp(i,j,7), pow(i,j,7)
