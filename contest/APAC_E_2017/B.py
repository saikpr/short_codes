'''input
100
493
376
197
208
675
558
873
975
888
736
776
536
664
244
435
725
126
717
276
157
1000
784
685
616
918
984
798
503
845
747
644
694
487
854
823
528
414
113
144
936
543
296
58
65
563
705
238
93
654
357
766
364
326
423
218
133
573
946
385
514
585
464
906
306
167
393
344
758
637
448
863
476
814
404
967
184
893
255
8
316
38
226
455
263
44
807
177
15
597
604
927
283
336
834
958
25
107
88
77
623
'''
import math
def  calculate_sum(B,k):

    sum_val = 0

    for i in xrange(0,k):
        # print i
        sum_val += pow(B,i)
    # print B,k,sum_val
    return sum_val


def solve_N(N):

    Base = 2
    max_possible_count = 2
    
    for bits in xrange(64,2,-1):
        
        low =2
        high = N
        mid =(low +high)/2
        while(low<=high):
            mid =(low +high)/2
            val = calculate_sum(mid,bits)
            if val == N:
                break
            elif val>N:
                high = mid -1
            else:
                low = mid +1
        if (calculate_sum(mid,bits)==N):
            max_possible_count = max(bits,max_possible_count)

                
    return max_possible_count


if __name__ == "__main__":
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        print "Case #"+str(t+1)+": "+ str(solve_N(N))