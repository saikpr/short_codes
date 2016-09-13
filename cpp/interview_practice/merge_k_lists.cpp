/*input
5
5
10 9 7 6 3
100 52 16 9 3 
52 36 9 5 3
85 63 21 10 2
996 58 6 2 1
*/
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 100
using namespace std;
bool is_done(vector<int> &vec, vector<vector<int> > &vec2)
{
	for(size_t i =0;i<vec.size();i++)\
	{
		if(vec[i]!=vec2[i].size()-1)
			return false;
	}
return true;
}
vector<int> merge_k(vector<vector<int>> &vec)
{
	int k =vec.size();
	// cout<<k<<endl;
	vector<int> index(k,0);
	vector<int> to_return;
	priority_queue<pair<int,int>> p1;
	for(size_t i =0;i<k;i++)
	{
		p1.push(make_pair(vec[i][0],i));
		index[i]++;
	}
	while(is_done(index,vec)==false)
	{
		
		pair<int,int> temp = p1.top();
		p1.pop();
		to_return.push_back(temp.first);
		
		if(index[temp.second]<vec[temp.second].size()-1)
		{	index[temp.second]++;
			p1.push(make_pair(vec[temp.second][index[temp.second]],temp.second));
		}



	}
	// cout<<to_return.size()<<endl;
	while(p1.empty()==false)
	{
	to_return.push_back(p1.top().first);
	p1.pop();
	}
	// cout<<to_return.size()<<endl;
return to_return;
}


int main()
{
	int k;
	int n;
	cin>>k;
	cin>>n;
	vector<vector<int> > vec(k,vector<int>(n,0));
	// cout<<vec.size()<<endl;
	for(size_t i =0;i<k ; i++)
	{
		for (size_t j =0;j<n;j++)
		{
			cin>>vec[i][j];
		}
	}

	vector<int> vp = merge_k(vec);
	for(size_t i =0;i<vp.size() ; i++)
	{
		cout<<vp[i]<<" ";
	}
}