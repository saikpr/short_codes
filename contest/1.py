if __name__=="__main__":
	str1=str(raw_input())
	n,k=str1.split()
	n=int(n)
	k=int(k)
	sum1=0
	fact=1
	for i in xrange(1,n+1):
		if i%1000==0:
			print i
		fact=fact*i
		sum_numbers=str(fact)
		
		sum_numbers=sum_numbers.replace('0','')
		
		if len(sum_numbers) > k:
			sum_numbers=sum_numbers[len(sum_numbers)-k:]
		else:
			sum_numbers=sum_numbers
		
		sum1+=int(sum_numbers)

	print sum1+1