#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstdlib>
#include <tuple>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& vec1, vector<int>& vec2, int k)
 
{
	priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> > , greater<tuple<int,int,int> > > p1;
 
 
	std::vector<pair<int,int> > to_return;
	map <pair<int,int>,bool > map_el;
	if(vec1.size()==0||vec2.size()==0)
	return to_return;
	p1.push(make_tuple(vec1[0]+vec2[0],0,0));
	map_el.insert(make_pair(make_pair(0,0),true));
	int count =0;
	while (to_return.size()<k&&p1.size()!=0)
	{
		tuple<int,int,int> temp = p1.top();
		p1.pop();
		to_return.push_back(make_pair(vec1[get<1>(temp)],vec2[get<2>(temp)]));
 
		count++;
		if(get<1>(temp)<vec1.size()-1 &&map_el.count(make_pair(get<1>(temp)+1,get<2>(temp)))==0)
		{
			p1.push(make_tuple(vec1[get<1>(temp)+1]+vec2[get<2>(temp)],get<1>(temp)+1,get<2>(temp)));
			map_el.insert(make_pair(make_pair(get<1>(temp)+1,get<2>(temp)),true));
		}
		if(get<2>(temp)<vec2.size()-1&&map_el.count(make_pair(get<1>(temp),get<2>(temp)+1))==0)
		{
			p1.push(make_tuple(vec1[get<1>(temp)]+vec2[get<2>(temp)+1],get<1>(temp),get<2>(temp)+1));
			map_el.insert(make_pair(make_pair(get<1>(temp),get<2>(temp)+1),true));
		}
 
 
	}
	return to_return;
} 
 
};
 
 
int main()
{
	int n1;
	cin>>n1;
	int n2;
	cin>>n2;
	int k;
	cin>>k;
	vector<int> vec1(n1),vec2(n2);
 
 
	for(size_t i =0 ; i<n1;i++)
	cin>>vec1[i];
	for(size_t i =0 ; i<n2;i++)
	cin>>vec2[i];
	Solution temp;
	vector<pair<int,int> > temp_pairs = temp.kSmallestPairs(vec1,vec2,k);
	for(size_t i=0 ; i < temp_pairs.size();i++)
	{
		cout<<temp_pairs[i].first<<" "<<temp_pairs[i].second<<endl;
	}
 
 
}