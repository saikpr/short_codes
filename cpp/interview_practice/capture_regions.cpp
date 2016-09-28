/*input
3
OOOO
OOOX
XXXX
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
#include <cassert>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const vector<pair<int,int> > possible_dir ={make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)};

vector<pair<int,int > > generate_candidates(pair<int,int> &boundary, pair<int,int> &seed)
{
	vector<pair<int,int> > return_vector;
	if (seed.first<0||seed.second<0||seed.first>=boundary.first||seed.second>=boundary.second)
		return return_vector;
	for(size_t i = 0 ; i< possible_dir.size(); i++)
	{
		pair<int,int> delta = possible_dir[i];

		if((seed.first + delta.first)>=0 && 
			(seed.first + delta.first)<boundary.first &&
			(seed.second+delta.second)>=0&&
			(seed.second +delta.second)<boundary.second)
			{
				return_vector.push_back(make_pair(seed.first + delta.first,seed.second + delta.second));
			}
	}

	return return_vector;
}


void bfs(vector<string> &vec,vector<vector<bool> > &visited, pair<int,int> seed)
{
	assert(vec.size()>0&&vec[0].size()>0);
	bool to_color =true;
	if (seed.first == 0 ||seed.second == 0 ||seed.first==vec.size()-1 || seed.second == vec[0].size()-1)
	to_color =  false;
	pair<int,int> boundary = make_pair(vec.size(),vec[0].size());
	vector<pair<int,int> > path;
	queue<pair<int,int> > que;
	que.push(seed);
	int k=que.size();
	while(k!=0)
	{	
		// cout<<k<<"dfgdf"<<endl;
		// cout<<"Ehil"<<endl;
		pair<int,int> temp = que.front();
		que.pop();
		// cout<<temp.first<<" "<<temp.second<<endl;
		// path.push_back(temp);
		vector<pair<int,int> > possible_positions = generate_candidates(boundary,temp);
		// cout<<possible_positions.size()<<endl;
		// if (temp.first == 0 ||temp.second == 0 ||temp.first==vec.size()-1 || temp.second == vec[0].size()-1)
		// 	to_color =  false;

		for(size_t i = 0 ; i < possible_positions.size();i++)
		{
			pair<int,int> this_pos = possible_positions[i];
			// cout<<this_pos.first<<" "<<this_pos.second<<endl;
			if((this_pos.first)<0 || 
				(this_pos.first)>=boundary.first ||
				(this_pos.second)<0||
				(this_pos.second)>=boundary.second)
				continue;

			if(vec[this_pos.first ][this_pos.second]=='O' && visited[this_pos.first ][this_pos.second]==false)
			{
				visited[this_pos.first ][this_pos.second] = true;
				que.push(this_pos);
			}

		}
		// cout<<possible_positions.size()<<"END"<<endl;
		// cout<<que.size()<<endl;
		// cout<<que.front().first<<" "<<que.front().second<<endl;
		// cout<<"Whl end"<<endl;
		// cout<<que.size()<<endl;
		k=que.size();
		// cout<<k<<endl;
		
	}
	if(to_color==true)
	{
		for(size_t i = 0 ; i < path.size();i++)
		{
			vec[path[i].first ][path[i].second ] = 'X';
		}
	}
	cout<<"Exit"<<endl;
	return;
}



void color_the_box(vector<string> &vec)
{
	assert(vec.size()>0&&vec[0].size()>0);
	pair<int,int> boundary = make_pair(vec.size(),vec[0].size());
	// cout<<boundary.first<<" "<<boundary.second<<endl;
	vector<vector<bool > > visited(boundary.first,vector<bool>(false,boundary.second));
	// bfs(vec,visited,make_pair(i,j));
	for(size_t i = 1 ; i < boundary.first-1; i ++)
	{
		for(size_t j = 1; j < boundary.second-1; j++)
		{
			if(vec[i][j]=='O' && visited[i][j]==false)
			{
				visited[i][j]==true;
				bfs(vec,visited,make_pair(i,j));

			}
		}
	}

}

int main()
{
	int n ; 
	cin>>n;
	vector<string> vec(n);
	string temp;
	cout<<n<<endl;
	for(size_t i = 0 ; i<n ; i++)
	{
		cin>>vec[i];
		// cout<<vec[i].size()<<endl;
	}
	color_the_box(vec);
	for(size_t i = 0 ; i<n ; i++)
	{
		cout<<vec[i]<<endl;
	}
	return 0 ;
}
