'''input
50
6 4229 4808 66 21 13
7 1230 6598 35 29 36
8 5978 3308 71 29 0
9 7081 5231 78 9 13
8 7552 3703 52 18 30
5 2822 2887 32 66 2
10 8191 0 10 30 60
1 9216 8704 1 98 1
10 0 8191 10 80 10
9 9888 5834 55 16 29
5 8191 0 10 30 60
5 8525 2059 1 78 21
7 4188 6772 65 23 12
1 8191 0 10 30 60
9 5973 7383 53 1 46
5 6973 7672 19 27 54
10 9216 8704 33 33 34
5 9216 8704 1 1 98
5 5945 2829 46 39 15
8 7608 3150 66 28 6
10 9216 8704 98 1 1
5 0 8191 10 80 10
8 6738 4672 77 8 15
10 9216 8704 1 98 1
8 4951 5554 89 2 9
9 4646 1476 41 8 51
3 7840 4046 22 33 45
9 2710 7061 100 0 0
6 4769 9477 28 0 72
4 9310 9540 22 33 45
5 9356 2372 45 47 8
5 5871 8306 59 14 27
1 1667 696 22 33 45
9 5117 1495 29 39 32
7 8082 5967 27 27 46
5 9216 8704 98 1 1
1 0 8191 10 80 10
1 9216 8704 98 1 1
9 6783 6427 58 12 30
9 3704 1603 68 22 10
1 9216 8704 1 1 98
9 2474 6792 40 28 32
2 991 5210 22 33 45
5 9216 8704 1 98 1
7 6222 7971 78 5 17
9 5590 2749 32 18 50
10 9216 8704 1 1 98
8 3364 2148 78 3 19
5 4633 7402 33 66 1
9 8078 5492 51 16 33
'''


def one_engine(A,B,C,K,possible_value):

	val_A = K&possible_value
	val_B = K|possible_value
	val_C = K^possible_value
	the_dict = dict()
	if val_A not in the_dict:
		the_dict[val_A]=0
	if val_B not in the_dict:
		the_dict[val_B]=0
	if val_C not in the_dict:
		the_dict[val_C]=0
	the_dict[val_A]+=A*1.0/100
	the_dict[val_B]+=B*1.0/100
	the_dict[val_C]+=C*1.0/100
	return the_dict


def n_engines(input_val):
	N,X,K,A,B,C=input_val
	possible_values = one_engine(A,B,C,K,X)
	
	for i in xrange(N-1):
		prev_candidates = possible_values.keys()
		temp_possible_values_dict = dict()
		for each_candidate in  prev_candidates:
			the_possibl_dict = one_engine(A,B,C,K,each_candidate)
			for each_key in the_possibl_dict:
				the_possibl_dict[each_key] = the_possibl_dict[each_key]*possible_values[each_candidate]
				if each_key not in temp_possible_values_dict:
					temp_possible_values_dict[each_key]=0
				temp_possible_values_dict[each_key]+=the_possibl_dict[each_key]
		# print temp_possible_values_dict
		possible_values = temp_possible_values_dict
	return possible_values
if __name__=="__main__":
	T = int(raw_input())
	for t in xrange(T):
		input_val = raw_input().split()
		input_val = map(int,input_val)
		# print input_val()
		temp = n_engines(input_val)
		sum_val =0.0
		for each_key in temp:
			sum_val +=temp[each_key]*each_key
		print "Case #"+str(t+1) + ": "+str(sum_val)
		# print one_engine(input_val[3],input_val[4],input_val[5],input_val[2],input_val[1])