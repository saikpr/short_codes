/*input
1
5 5
769 904 679 866 793
399 235 429 691 723
823 373 489 45 926
348 518 220 504 845
503 125 83 932 28
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <string>
#include <stack>
using namespace std;
const long long int MAX_INT = (int)(~0U>>1);

long long find_sum (std::vector<vector<int>> &new_vec)
{
	int R = new_vec.size();
	int C= new_vec[0].size();
	vector <std::vector<int > > components(R,vector<int>(C,-1));
	vector <std::vector<bool > > visited(R,vector<bool>(C,false));
	int component = 0;

	for(size_t i =0 ;i<R;i++)
	{
		for(size_t j=0;j<C;j++)
		{
			if (visited[i][j]==false)
			{
				stack < pair<int,int>> s1;
				s1.push(make_pair(i,j));
				while(s1.empty()==false)
				{
					// cout<<s1.size();
					pair <int,int> coord = s1.top();
					components[coord.first][coord.second] = component;
					visited[coord.first][coord.second]=true;
					s1.pop();
					if(coord.first-1>=0 
						&& visited[coord.first-1][coord.second] ==false 
						&&new_vec[coord.first][coord.second] ==new_vec[coord.first-1][coord.second])
					{
						s1.push(make_pair(coord.first-1,coord.second));
					}
					if(coord.first+1<R
						&& visited[coord.first+1][coord.second] ==false 
						&&new_vec[coord.first][coord.second] ==new_vec[coord.first+1][coord.second])
					{
						s1.push(make_pair(coord.first+1,coord.second));
					}
					if(coord.second-1>=0 
						&& visited[coord.first][coord.second-1] ==false 
						&&new_vec[coord.first][coord.second] ==new_vec[coord.first][coord.second-1])
					{
						s1.push(make_pair(coord.first,coord.second-1));
					}
					if(coord.second+1<C
						&& visited[coord.first][coord.second+1] ==false 
						&&new_vec[coord.first][coord.second] ==new_vec[coord.first][coord.second+1])
					{
						s1.push(make_pair(coord.first,coord.second+1));
					}

				}
				component++;
			}
		}
	}
	// cout<<component<<endl;
	vector< pair<int,int>> p1(component, make_pair(-1,-1));
	priority_queue<pair<int,int> > height_component;
	for(size_t i =0 ; i<R;i++)
	{
		for(size_t j =0 ; j < C;j++)
		{
			if(p1[components[i][j]]==make_pair(-1,-1))
			{
				p1[components[i][j]]=make_pair(i,j);
				height_component.push(make_pair(-1*new_vec[i][j],components[i][j]));
			}
			visited[i][j]=false;
		}

	}
	std::vector<int> component_min_height(component,MAX_INT);
	// cout<<height_component.size()<<endl;
	while(height_component.empty()==false)
	{
		int i = height_component.top().second;
		height_component.pop();
		pair<int,int> coord = p1[i];
		int surrounding_min_height = MAX_INT;

		for (int index_i = 0;index_i<R;index_i++)
		{
			for (int index_j=0;index_j<C;index_j++)
			{
				if (components[index_i][index_j]==i)
				{
					//UP
					if (index_i-1>=0&&components[index_i-1][index_j]!=i)
					{
						// cout<<index_i-1<<index_j<<endl;
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i-1][index_j]);
					}
					else
					if (index_i-1<0)
					{
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j]);
					}

					//DOWN
					if (index_i+1<R&&components[index_i+1][index_j]!=i)
					{
						// cout<<index_i+1<<index_j<<endl;
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i+1][index_j]);
					}
					else
					if (index_i+1>=R)
					{
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j]);
					}


					if (index_j-1>=0&&components[index_i][index_j-1]!=i)
					{
						// cout<<index_i-1<<index_j<<endl;
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j-1]);
					}
					else
					if (index_j-1<0)
					{
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j]);
					}

					if (index_j+1<C&&components[index_i][index_j+1]!=i)
					{
						// cout<<index_i+1<<index_j<<endl;
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j+1]);
					}
					else
					if (index_j+1>=C)
					{
						surrounding_min_height = min(surrounding_min_height,new_vec[index_i][index_j]);
					}
				}
				component_min_height[i]=min(component_min_height[i],surrounding_min_height);
			}
		}
	}

	// for(size_t i =0 ; i<component_min_height.size();i++)
	// {
	// 	cout<<component_min_height[i]<<" ";
	// }
	// cout<<endl;

	for(size_t i =0 ; i<R;i++)
	{
		for(size_t j =0 ; j < C;j++)
		{
			if(component_min_height[components[i][j]]>new_vec[i][j])
			{
				new_vec[i][j] = component_min_height[components[i][j]];
			}
		}
		// cout<<endl;
	}

	// for(size_t i =0 ; i<R;i++)
	// {
	// 	for(size_t j =0 ; j < C;j++)
	// 	{
	// 		cout<<components[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	long long sum_heights = 0;
	for(size_t i =0 ; i<R;i++)
	{
		for(size_t j =0 ; j < C;j++)
		{
			sum_heights+=new_vec[i][j];
			// cout<<new_vec[i][j]<<" ";
		}
		// cout<<endl;
	}
	return sum_heights;
}

int main()
{
	int T;
	cin>>T;
	for (size_t i =0;i<T;i++)
	{
		int R,C;
		cin>>R>>C;
		std::vector<vector<int>> vec(R,vector<int>(C,0));
		long long old_sum=0;
		for (size_t j =0 ;j <R;j++)
		{
			for (size_t k = 0; k<C; ++k)
			{
				cin>>vec[j][k];
				old_sum+=vec[j][k];
				// cout<< vec[j][k];
			}
		}
		cout<<"Case #"<<i+1<<": ";
		for (size_t j =0 ;j <max(R,C);j++)
		{
			find_sum(vec);
		}
		cout<<find_sum(vec)-old_sum<<endl;
	}
}