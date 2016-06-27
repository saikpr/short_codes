/*input
4
1010
1011
1011
0100
*/

#include <iostream>
#include <stack>
#include <array>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#define MAXN 4
using namespace std;


vector < vector<int>> valid_moves({{-1,0},{0,-1},{0,1},{1,0}});

typedef vector<bitset<MAXN>>  my_bitset;
int count_connected_sets(my_bitset &b,const int  n)
{
	vector<vector<int>> ref_vec(n,vector<int>(n,-1)),visited(n,vector<int>(n,0));

	int index =0;
	queue < pair<int,int> > q1;
	for (size_t i=0; i<n;i++)
	{
		for(size_t j=0; j <n;j++)
		{
			if (b[i][j] == 1&&visited[i][j]==0)
			{	visited[i][j] =1;
				q1.push(make_pair(i,j));
				index++;
				cout<<index<<" "<<i<<","<<j<<endl;
				ref_vec[i][j]=index;

				while(q1.empty()==false)
				{	int index_i,index_j;
					tie(index_i,index_j) = q1.front();
					cout<<"queue pop "<<index<<" "<<index_i<<","<<index_j<<endl;
					q1.pop();
					assert(valid_moves.size()>0);
					for (size_t valid_mov_i =0;valid_mov_i<valid_moves.size();valid_mov_i++ )
					{	
						int this_index_i = index_i+valid_moves[valid_mov_i][0];
						int this_index_j = index_j+valid_moves[valid_mov_i][1];
						// cout<<"Checking"<<this_index_i<<this_index_j<<endl;
						if(this_index_i>=0&&this_index_i<n&&this_index_j>=0&&this_index_i<n)
						{
							// cout<<"Trying"<<this_index_i<<this_index_j<<" is cvisited"<<visited[this_index_i][this_index_j]<<endl;

							if(b[this_index_i][this_index_j]==1 &&visited[this_index_i][this_index_j]==0 )
							{
								visited[this_index_i][this_index_j] =1;
								ref_vec[this_index_i][this_index_j]=index;
								cout<<index<<" "<<this_index_i<<","<<this_index_j<<endl;
								q1.push(make_pair(this_index_i,this_index_j));
							}
						}
					}
				}

				
			}
		}
	}
	for (size_t i=0; i<n;i++)
	{
		for(size_t j=0; j <n;j++)
		{
			cout<<ref_vec[i][j];
		}
		cout<<endl;
	}
}


int main()
{
int n;
cin>>n;
string temp;
vector<bitset<MAXN>> b1;
for (size_t i =0;i<n;i++)
{
	cin>>temp;
	assert(temp.size()==n);
	bitset<MAXN> bit_temp(temp);
	b1.push_back(bit_temp);

}
for (size_t i =0;i<n;i++)
{
	cout<<b1[i]<<endl;

}
count_connected_sets(b1, n);
}