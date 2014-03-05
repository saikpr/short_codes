def isprime(n):
    if n==1:
        return 1

    if n == 2:
        return 1
    if n % 2 == 0:
        return 0
    max = n**0.5+1
    i = 3
    while i <= max:
        if n % i == 0:
            return 0
        i+=2
    return 1
if __name__=="__main__":
    str1=str(raw_input())
    n,k=str1.split()
    n=int(n)
    k=int(k)
    lastperson=[]
    roomnumber=[]
    for i in xrange(0,1000000):
        lastperson+=[0]
        roomnumber+=[0]
    floor=-1
    room=-1
    checkt=False
    person=1
    while checkt==False:
        if floor==n and room==k:
            checkt=True
            print person-1
            break
        for i in xrange(1,1000000):
            if isprime(lastperson[i] +person) ==1 and lastperson[i]!=0:
                lastperson[i]=person
                roomnumber[i]+=1
                floor=i
                room = roomnumber[i] 
                
                break
            elif lastperson[i]==0:
                lastperson[i]=person
                roomnumber[i]+=1
                floor=i
                room = roomnumber[i] 
                break
        person+=1
