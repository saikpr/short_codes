/*input
2
4 6
10
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
#define MAXN 4
using namespace std;

struct ToastCompare
{
	bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const
	{
		return p1.first*p1.second > p2.first*p2.second;
	}
};

int print_n_multiple(std::vector<int> &vec, int k)
{
	int n=vec.size();

	std::priority_queue<pair<int,int> , vector<pair<int,int> > , ToastCompare> pq1;
	for (size_t i =0;i<n;i++)
	{
		pq1.push(make_pair(vec[i],1));
		// cout<<vec[]
	}
	while(k-->0)
	{
		pair<int,int> p1 = pq1.top();
		cout<<p1.first*p1.second<<endl;
		pq1.pop();
		// cout<<p1.first*p1.second<<pq1.top().first<<endl;
		while(pq1.top().first*pq1.top().second == p1.first*p1.second)
		{
			pair<int,int> p2 = pq1.top();
			pq1.pop();
			pq1.push(make_pair(p2.first,p2.second+1));
		}
		pq1.push(make_pair(p1.first,p1.second+1));
		// cout<<p1.first<<p1.second+1<<endl;
	}
}

int main()
{
	int N;
	cin>>N;
	std::vector<int> vec(N);
	for(size_t i =0 ; i< N ; i++)
	{
		cin>>vec[i];
	}
	int k;
	cin>>k;
	print_n_multiple(vec,k);
}