/*input
6 5
2 3
3 1
0 3
4 0
1 4
*/#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;


typedef map<int,set<int> > adj_ct;
bool dfs_util(adj_ct &adj_list,int start, set<int> &isVisited, set<int> &instack,vector<int> &to_return)
{
	if(isVisited.count(start)==1)
		return true;
	if(instack.count(start)==1)
		return false;
	instack.insert(start);

	set<int> &neig = adj_list[start];

	for(auto it=neig.begin();it!=neig.end();it++)
	{
		if(!dfs_util(adj_list,*it,isVisited,instack,to_return))
			return false;
	}
	instack.erase(start);
	isVisited.insert(start);
	to_return.push_back(start);
	return true;
}

vector<int> topological_sort(int count,vector<pair<int,int>> &dependency)
{
	vector<int> to_return;
	set<int> possible_start;
	adj_ct adj_list;
	for(int i= 0;i<count;i++)
	{
		possible_start.insert(i);
		adj_list[i] = set<int>();
	}
	
	for(size_t i = 0 ; i < dependency.size();i++)
	{
		adj_list[dependency[i].second].insert(dependency[i].first);
		if(possible_start.count(dependency[i].first)==1)
		{
			possible_start.erase(dependency[i].first);
		}
	}
	set<int> instack,isVisited;
	for(auto it=possible_start.begin();it!=possible_start.end();it++)
	{
		if(dfs_util(adj_list,*it,isVisited,instack,to_return)==false)
			return vector<int>();
	}
	return to_return;
}

int main()
{
	int N,M;
	cin>>N>>M;
	vector<pair<int,int> > dependency;
	for(size_t m = 0 ; m <M;m++)
	{
		int u,l;
		cin>>u>>l;
		dependency.push_back(make_pair(u,l));

	}
	std::vector<int> solu=topological_sort(N,dependency);
	for(size_t i = 0 ; i < solu.size();i++)
	{
		cout<<solu[i]<<endl;
	}
	cout<<solu.size()<<endl;
}