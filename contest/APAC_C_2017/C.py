'''input
4
3
a=f(b,c)
b=g()
c=h()
2
a=f(b)
b=f(a)
2
aaa=foo(x,y)
bbb=bar(aaa,bbb)
2
x=f()
y=g(x,x)
'''
import sys
sys.setrecursionlimit(1500)
def cycle_exists(G):                     # - G is a directed graph
    color = { u : "white" for u in G  }  # - All nodes are initially white
    found_cycle = [False]                # - Define found_cycle as a list so we can change
                                         # its value per reference, see:
                                         # http://stackoverflow.com/questions/11222440/python-variable-reference-assignment
    for u in G:                          # - Visit all nodes.
        if color[u] == "white":
            dfs_visit(G, u, color, found_cycle)
        if found_cycle[0]:
            break
    return found_cycle[0]
 
#-------
 
def dfs_visit(G, u, color, found_cycle):
    if found_cycle[0]:                          # - Stop dfs if cycle is found.
        return
    color[u] = "gray"                           # - Gray nodes are in the current path
    for v in G[u]:                              # - Check neighbors, where G[u] is the adjacency list of u.
        if color[v] == "gray":                  # - Case where a loop in the current path is present.  
            found_cycle[0] = True       
            return
        if color[v] == "white":                 # - Call dfs_visit recursively.   
            dfs_visit(G, v, color, found_cycle)
    color[u] = "black"  



if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		N = int(raw_input())
		graph_var = dict()
		str_to_vert = dict()
		vertex_number = 0

		for n in xrange(N):
			str_val = raw_input().rstrip().split("=")
			left_vert = str_val[0]
			# right_vert = []
			right_vert = str_val[1].split("(")[1][:-1].split(",")
			# print left_vert,right_vert
			left_var_name = -1
			if left_vert not in str_to_vert:
				
				str_to_vert[left_vert]= vertex_number
				vertex_number+=1
			left_var_name = str_to_vert[left_vert]

			right_vert_name = []
			for each_vert in right_vert:
				if each_vert is '':
					continue
				this_var_name = -1
				if each_vert not in str_to_vert:
				
					str_to_vert[each_vert]= vertex_number
					vertex_number+=1
				this_var_name = str_to_vert[each_vert]
				right_vert_name.append(this_var_name)

			graph_var[left_var_name] = right_vert_name
			# print right_vert_name,left_var_name
		# for each_v in str_to_vert:
		# 	if str_to_vert[each_v] not in graph_var:
		# 		graph_var[str_to_vert[each_v]] =[]
		# graph_var = {}
		# print str_to_vert
		# print cycle_exists(graph_var)
		try:
			bool_test = cycle_exists(graph_var)
		except KeyError:
			bool_test = True
		if bool_test:
			print "Case #"+str(t+1)+": BAD"
		else:
			print "Case #"+str(t+1)+": GOOD"