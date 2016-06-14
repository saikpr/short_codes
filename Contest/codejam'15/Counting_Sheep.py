
def find_last(n):
    if n<=0:
        return "Insomanic"
    n_set = set(str(n))
    _n = n
    i=1
    while len(n_set) != 10:
    	# print i
        n_set = n_set.union(set(str(i*n)))
        i+=1
    return (i-1)*n

if __name__ == "__main__":
    
    n = int(raw_input())

    for i in xrange(n):
    	this_elem = int(raw_input())
    	print find_last(this_elem)