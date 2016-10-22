'''input
1
1
F8
CC
AA
'''

def check_aorb(A,B,C,k):

    temp_k=0
    A_new = list(A)
    B_new = list(B)
    C=list(C)
    # print ''.join(A), ''.join(B), ''.join(C)
    for i in xrange(len(C)):
        if C[i]=='0':
            if A_new[i]=='1':
                temp_k+=1
                A_new[i]='0'
            if B_new[i]=='1':
                temp_k+=1
                B_new[i]='0'
    for i in xrange(len(C)):
        if C[i]=='1' and (A_new[i]==B_new[i]=='0'):
            temp_k+=1
            B_new[i]='1'
    if (temp_k == k):
        return hex(int(''.join(A_new),2)),hex(int(''.join(B_new),2)),hex(int(''.join(C),2))
    if (temp_k>k):
        return -1
    for i in xrange(len(C)):
        if (A_new[i]=='1'):
            if (B_new[i]=='1'):
                temp_k+=1
                A_new[i]='0'
                if(temp_k==k):
                    break
            elif B_new[i]=='0'and (temp_k+1)!=k:
                temp_k+=2
                A_new[i]='0'
                B_new[i]='1'
                if(temp_k==k):
                    break


    # if (temp_k == k):
    #     return hex(int(''.join(A_new),2)),hex(int(''.join(B_new),2)),hex(int(''.join(C),2))
    if (temp_k>k):
        return -1

    return hex(int(''.join(A_new),2)),hex(int(''.join(B_new),2)),hex(int(''.join(C),2))



if __name__ =="__main__":
    # k = raw_input()
    # print k

    n=int(raw_input())
    for ind in xrange(n):
        k=int(raw_input())
        A=bin(int(raw_input(),16))[2:]
        B=bin(int(raw_input(),16))[2:]
        C=bin(int(raw_input(),16))[2:]
        # print  
        n_str = max(len(A),len(B),len(C))
        # print n,A,B,C
        # print n
        # print A.zfill(n),B.zfill(n),C.zfill(n)
        ret_val =  check_aorb(A.zfill(n_str),B.zfill(n_str),C.zfill(n_str),k)
        if (ret_val != -1):
            # print bin(int(ret_val[0][2:].upper(),16))[2:],
            # print bin(int(ret_val[1][2:].upper(),16))[2:],
            # print bin(int(ret_val[2][2:].upper(),16))[2:]
            print ret_val[0][2:].upper().replace ("L","")
            print ret_val[1][2:].upper().replace ("L","")
        else:
            print -1

        # for i in xrange(16):
        #     print 
        #     print i
        #     ret_val =  check_aorb(A.zfill(n_str),B.zfill(n_str),C.zfill(n_str),i)
        #     if (ret_val != -1):
        #         print bin(int(ret_val[0][2:].upper(),16))[2:],
        #         print bin(int(ret_val[1][2:].upper(),16))[2:],
        #         print bin(int(ret_val[2][2:].upper(),16))[2:]
        #         print ret_val[0][2:].upper()
        #         print ret_val[1][2:].upper()
        #     else:
        #         print -1