/*input
1
5 5
5 4 3 2 1
1 1
1 10
1 15
3 8
4 11
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

void make_sum_array(std::vector<long long unsigned int> &vec)
{
	long long unsigned int N=vec.size();
	long long unsigned int sum=0;
	vec.resize(N+1);
	N=vec.size();
	vec[N]=0;
	long long unsigned int temp;
	for(size_t i=0;i<N;i++)
	{	
		// cout<<sum<<" ";
		temp = vec[i];	
		vec[i] = sum;
		sum += temp;

	}
}

void make_subarray(std::vector<long long unsigned int> &old_vec,std::vector<long long unsigned int>  &new_vec)
{
	
	
	make_sum_array(old_vec);
	long long unsigned int N= old_vec.size();
	// new_vec.push_back(old_vec[0]);
	for(size_t i=1;i<N;i++)
	{
		new_vec.push_back(old_vec[i]-old_vec[i-1]);
	}

	for(size_t i=0;i<N;i++)
	{
		for(size_t j=i+2;j<N;j++)
		{
			new_vec.push_back(old_vec[j]-old_vec[i]);
		}
	}
	sort(new_vec.begin(),new_vec.end());
	make_sum_array(new_vec);
	// for(size_t i=0;i<new_vec.size();i++)
	// {
	// 	cout<<new_vec[i]<<" ";

	// }

}

int main()
{
	long long unsigned int T;
	cin>>T;
	std::vector< long long unsigned int > vec;
	long long unsigned int temp;
	for (size_t index=0 ; index<T;index++)
	{	
		long long unsigned int Q,N;
		cin>>N>>Q;
		vec.resize(N);
		for(size_t ind =0;ind<N;ind++)
		{
			cin>>temp;
			vec[ind]=temp;
		}
		vector< long long unsigned int > new_vec;
		make_subarray(vec,new_vec);
		long long unsigned int index_i,index_j;
		cout<<"Case #"<<index+1<<":"<<endl;
		while(Q-->0)
		{
			cin>>index_i>>index_j;
			cout<<new_vec[index_j]-new_vec[index_i-1]<<endl;
		}
		// cout<<"Case #"<<index+1<<": "<<count_find(str,1000000007 )<<endl;

	}
}