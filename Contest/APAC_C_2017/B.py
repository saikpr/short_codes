'''input
2
3 3 1
2 1
4 11 12
0 1
0 3
0 4
0 10
1 0
1 9
2 0
2 4
2 9
2 10
3 4
3 10
'''
def countSquares( m,  n):
   m,n = min(m,n),max(m,n)

 
   return  m*(m+1)*(2*m+1)/6 + (n-m)*m*(m+1)/2;

def valid_square(t1,t2,max_edge,tup):
    bool_test =True

    if max(t1[0],t2[0])>=max_edge[0]:
        bool_test = False
    if max(t1[1],t2[1])>=max_edge[1]:
        bool_test = False
    if not(min(t1[0],t2[0])<=tup[0]<=max(t1[0],t2[0])):
        bool_test = False
    if not(min(t1[1],t2[1])<=tup[1]<=max(t1[1],t2[1])):
        bool_test = False
    return bool_test


def generate_squares(t1,max_edge):
    t_new_1 = None
    t_new_2 = None
    tuple_sq = set()
    for i in xrange(max_edge[0]):
        for j in xrange(max_edge[1]):
            for k in xrange(min(max_edge)):
                t_new_1 = (i,j)
                t_new_2 = (i+k,j+k)
                # print t_new_1,t_new_2
                if valid_square(t_new_1,t_new_2,max_edge,t1):
                    tuple_sq.add((min(t_new_1,t_new_2),max(t_new_1,t_new_2)))
    return tuple_sq


if __name__=="__main__":
    T = int(raw_input())
    for t in xrange(T):
        R,C,K = map(int,raw_input().split())
        max_edge = (R,C)
        squares_set = set()
        monsters = set()
        for k in xrange(K):
            i,j = map(int,raw_input().split())
            monsters.add((i,j))
        max_sq = countSquares(R,C)
        for each_monster in monsters:
            # print each_monster
            tuple_sq = generate_squares(each_monster,max_edge)
            # print tuple_sq
            for each in tuple_sq:
                squares_set.add(each)
        this_sq = (len(squares_set))
        print "Case #"+str(t+1)+": " + str(max_sq-this_sq)


