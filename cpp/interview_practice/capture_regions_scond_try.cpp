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

typedef  pair<int,int> pi;
typedef  vector<pair<int,int> > vp;
typedef  vector<string > vs;
typedef  vector<vector<bool> > vvb;

vp generate_sols(pi seed,pi boundary)
{
	vp returnvec;
	if (seed.first<0||seed.second<0||seed.first>=boundary.first||seed.second>=boundary.second)
		return returnvec;
	for(size_t i =0 ; i< possible_dir.size();i++)
	{
		pi temp = seed;
		temp.first +=possible_dir[i].first;
		temp.second +=possible_dir[i].second;
		if(temp.first>=0&&temp.second>=0&&temp.first<boundary.first&&temp.second<boundary.second)
		{
			returnvec.push_back(temp);
		}

	}
	return returnvec;
}

void bfs(vs &vec, vvb &visit , pi seed)
{
	// cout<<"En"<<endl;
	assert(vec.size()>0&&vec[0].size()>0);
	pi boundary = make_pair(vec.size(),vec[0].size());
	vp path;
	queue<pi> que;
	bool to_color = true;
	


	if (seed.first<=0||seed.second<=0||seed.first>=boundary.first-1||seed.second>=boundary.second-1)
		to_color = false;
	
	que.push(seed);


	while(que.empty()==false)
	{
		pi coord = que.front();
		que.pop();
		path.push_back(coord);
		vp possible_coor = generate_sols(coord,boundary);

		for(size_t i = 0; i < possible_coor.size();i++)
		{
			pi new_coord = possible_coor[i];
			if(visit[new_coord.first][new_coord.second]==false&& vec[new_coord.first][new_coord.second]=='O')
			{
				visit[new_coord.first][new_coord.second] = true;
				que.push(new_coord);
				if (new_coord.first<=0||new_coord.second<=0||new_coord.first>=boundary.first-1||new_coord.second>=boundary.second-1)
    				to_color = false;

			}
			
		}
	}

	if (to_color ==true)
	{
		for(size_t i = 0; i < path.size();i++)
		{
			vec[path[i].first][path[i].second] = 'X';
		}
	}
	return;
}


void color_box(vs &vec)
{
	assert(vec.size()>0&&vec[0].size()>0);
	pi boundary = make_pair(vec.size(),vec[0].size());
	vvb visit(boundary.first,vector<bool>(boundary.second,false));

	for(size_t i =0;i<boundary.first;i++)
	{
		for(size_t j =0 ; j < boundary.second;j++)
		{
			if (visit[i][j]==false && vec[i][j]=='O')
			{
				bfs(vec,visit,make_pair(i,j));
			}
		}
	}
}
void color_the_box(vs &vec)
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
// {
// 	vp t =generate_sols(make_pair(1,1),make_pair(23,2));
// 	cout<<t.size()<<endl;
// }