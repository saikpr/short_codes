/*input
5 6
1 3 5
4 5 0
2 1 3
3 2 1
4 3 4
4 2 2
*/
#include <map>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct  Node
{
	int data;
	vector <pair<int, int> > next;

	Node()
	{
		data =0;
	}
};

int sum_dfs(vector<Node> &vec_Node, int root,std::vector<bool> &vec_check,int sum_v=0)
{
	int sum_val = sum_v;
	// cout<<"r "<<root<<" "<<sum_val<<endl;
	vec_check[root]=true;
	int ind =0;
	int no_of_child = vec_Node[root].next.size();
	int this_sum = 0;
	while(ind<no_of_child)
	{	
		if (!vec_check[vec_Node[root].next[ind].first])
			{
				// cout<<root<<" "<< sum_val<<" "<<vec_Node[root].next[ind].first<<" "<<(1<<vec_Node[root].next[ind].second)<<endl;
				this_sum = (1<<vec_Node[root].next[ind].second);
				sum_val += sum_dfs(vec_Node,vec_Node[root].next[ind].first,vec_check,sum_v+this_sum);
				
			}
		ind++;
	}
	// cout<<"f "<<root<<sum_val<<endl;
	return sum_val;
}
int main()
{
	int N,M;
	cin>>N>>M;
	int M_temp = M;
	int A_i,B_i,C_i;
	vector<tuple<int,int,int> > vec(M);
	for(size_t i =0 ; i< M;i++)
	{
		cin>>A_i>>B_i>>C_i;
		vec[i] = make_tuple(C_i,min(A_i,B_i)-1,max(A_i,B_i)-1);
	}
	sort(vec.begin(),vec.end());
	vector < bool > vec_check(N,false);
	vector <Node> vec_Node (N);
	bitset<200000> b1;
	for(size_t i =0 ; i< N-1;i++)
	{	
		A_i = get<1> (vec[i]);
		B_i = get<2> (vec[i]);
		C_i = get<0> (vec[i]);
		vec_Node[A_i].next.push_back(make_pair(B_i,C_i));
		vec_Node[B_i].next.push_back(make_pair(A_i,C_i));
		// cout<< get<0> (vec[i])<<get<1>(vec[i])<<get<2>(vec[i])<<endl;
	}
	int sum_val;
	for(size_t i =0 ; i< N;i++)
	{
		sum_val += sum_dfs(vec_Node,i,vec_check);
		fill(vec_check.begin(),vec_check.end(),false);
	}
	cout<<sum_val/2;

}