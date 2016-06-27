'''input
1
1
F8
CC
AA
'''

if __name__=="__main__":
	N,M = raw_input().split(" ")
	N = int(N)
	M = int(M)
	M_temp = M
	l =list()
	while M-->0:
		A_i,B_i,C_i = raw_input().split(" ")
		C_i =int(C_i)
		l.append(C_i)
	l = sorted(l)
	for

