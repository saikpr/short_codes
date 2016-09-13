/*input
ZCRVpoDVpWvwexDhBm43OmKcSSq3EV89L1iEvZkFQ3CuwGZ4bt3uQFAWtnW8R4zOoFbPuFf9PWbZGxUaelCi88dLZMw77W2VGVtKO4rYl361MBRa51fdxb46zlNNOAViT718vddMQgPU30P3Vm4u5zVAXgOgN8fieoHwBLCID7GeZIMmxt6YZpvKKqRsfay1E0cgKjWvak9JHdwHSsoN8eRB0ZP6xRQojkIl8dqH6i5mQf21X7JhgJ5xd6smRbv0KPmyns3YHeNHc9oGNi4KGIhjiiaPYl4f8YQ6U7PEYIwv6guxv3QGpUcVEtwsydy53vTKppaXdQfrd4PSqnz8I4716g9fCSWzq8oMSsrir0u3k1IRIB75
dNaoGdgMNQG9
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
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int max_delta ( std::vector<deque<int> > &count_index)
{
	int max_index = -1;
	int min_index = 100000;
  for(size_t i =0 ;i<count_index.size();i++)
  {	
  	if (count_index[i].size()!=0)
  	{min_index = min ( min_index, count_index[i][0]);
  	max_index = max(max_index,count_index[i][count_index[i].size()-1]);}
  }
  assert(min_index<max_index);
  cout<<min_index<<" "<<max_index<<endl;

  return max_index-min_index+1;

}
int substring(string &s1, string &s2)
{
	vector<int> vec(256,-1);
	int min_delta = 100000;
	for(size_t i =0 ;i<s2.size();i++)
	{
		if (vec[s2[i]]==-1)
			vec[s2[i]]=0;
		vec[s2[i]]++;
	}
	// for(size_t i =0 ;i<vec.size();i++)
	// {
	// 	if (vec[i]!=-1)
	// 		// cout<<i<<" "<<vec[i]<<endl;
	// }
	std::vector<deque<int> > count_index(256,deque<int>(0));
	bool flag = false;
	for(size_t i =0;i<s1.size();i++)
	{
		if (vec[s1[i]]>0)
		{
			vec[s1[i]]--;
			count_index[s1[i]].push_back(i);
		}
		else if ( vec[s1[i]]==0)
		{
			count_index[s1[i]].pop_front();
			count_index[s1[i]].push_back(i);
		}

		if (vec[s1[i]]==0)
		{
			flag = true;
			// cout<<i<<" "<<s1[i]<<endl;

			for(size_t j =0 ; j < vec.size();j++)
			{
				if (vec[j]>0)
					flag = false;

			}
			if ( flag == true)
				{	
					// cout<<"flag"<<i<<endl;
					min_delta=min(min_delta,max_delta(count_index));
				}
		}

	}
	return min_delta;
}	


int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<substring(s1,s2);
}