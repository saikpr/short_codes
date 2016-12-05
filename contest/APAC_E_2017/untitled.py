'''input
'''

def calculate_bits(num):
    count = 0

    while(x!=0):
        count+=1
        x = x&(x-1)
        return count


if __name__ == "__main__":
    T = int(raw_input())

    for t in xrange(T):
        N = int(raw_input())
        print "Case #"+str(t+1)+": "+ str(calculate_bits(N))