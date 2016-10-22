'''input
8 8 1 1 8 8
'''
from  pprint import pprint
def generate_positions(pos,max_sides):
    def check_valid(new_pos):
        if all(i<=j for i,j in zip(new_pos,max_sides)) and all(i>0 for i in new_pos):
            return True
        return False
    _possible_direction = [(+2,-1) ,
                             (+2,+1) ,
                             (-2,+1) ,
                             (-2,-1) ,
                             (1,2) ,
                             (1,-2) ,
                             (-1,2) ,
                             (-1,-2)]
    possible_moves = []
    for each_dir in _possible_direction:
        new_pos = tuple(map(sum,zip(each_dir,pos)))
        if check_valid(new_pos):
            possible_moves.append(new_pos)
    return possible_moves

def generate_all_possible(pos,max_sides,mapping):
    if pos in mapping:
        return
    mapping[pos] = generate_positions(pos,max_sides)
    # print mapping[pos]
    moves = generate_positions(pos,max_sides)
    for each_new_pos in moves:
        if each_new_pos not in mapping:
            new_moves = generate_positions(each_new_pos,max_sides)
            mapping[each_new_pos] = generate_positions(each_new_pos,max_sides)
            for ec in new_moves:
                if ec not in mapping:
                    moves.append(ec)
    pprint (mapping)
    return

def knights_tour(N,M,x1,y1,x2,y2):
    # N,M,x1,y1,x2,y2 = map(int,raw_input().split())
    max_sides = (N,M)
    pos = (x1,y1)
    mapping = dict()

    generate_all_possible(pos,max_sides,mapping)
    # print len(mapping),"dsd"
    return bfs(pos,(x2,y2),mapping)
    # print bfs(pos,(pos[0]+2,mapping)


def bfs(start,end,mapping):
    moves_distance = dict()
    count=0
    if end not in mapping:
        return -1
    if start == end:
        return count
    # moves_distance = dict()

    possible_moves = mapping[start]
    while True:
        count+=1
        if not possible_moves :
            break
        new_possible_moves = []
        for each_position in possible_moves:
            if each_position in moves_distance:
                continue
            moves_distance[each_position] =  count
            # count+=1
            for ec in  mapping[each_position]:
                if ec not in moves_distance:
                    new_possible_moves.append(ec)
                else:
                    continue
        possible_moves = new_possible_moves
    if end in moves_distance:
        return moves_distance[end]
    return -1


if __name__ == "__main__":
    k = map(int,raw_input().split())
    print knights_tour(*k)




