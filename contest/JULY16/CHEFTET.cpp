/*input
3
1
10
20
4
15 7 10 10
6 14 21 1
3
1 100 3
1 2 3
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


int add_match(std::vector<int> &vecA,std::vector<int> &vecB)
{
	long long sum_val = 0;
	int N = vecB.size();
	for (size_t i =0;i<vecA.size();i++)
	{
		sum_val += vecA[i];
		sum_val += vecB[i];
	}
	long long necessary_sum = sum_val/(N);

	for(size_t i =0 ;i<N;i++)
	{
		vecA[i]=necessary_sum - vecA[i];
	}
	for(size_t i =0 ;i<N;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		
		if(vecA[i]== vecB[i])
		{
			vecA[i]= vecA[i] -vecB[i];
			vecB[i]=0;
		}
	}
	for(size_t i =1 ;i<N;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		if(vecA[i]== vecB[i-1])
		{
			vecA[i]= vecA[i] -vecB[i-1];
			vecB[i-1]=0;
		}
	}
	for(size_t i =0 ;i<N-1;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		if( vecA[i]== vecB[i+1])
		{
			vecA[i]= vecA[i] -vecB[i+1];
			vecB[i+1]=0;
		}
	}

	for(size_t i =0 ;i<N;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		
		if(vecA[i]>= vecB[i])
		{
			vecA[i]= vecA[i] -vecB[i];
			vecB[i]=0;
		}
	}
	for(size_t i =1 ;i<N;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		if(vecA[i]>= vecB[i-1])
		{
			vecA[i]= vecA[i] -vecB[i-1];
			vecB[i-1]=0;
		}
	}
	for(size_t i =0 ;i<N-1;i++)
	{	
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		if( vecA[i]>= vecB[i+1])
		{
			vecA[i]= vecA[i] -vecB[i+1];
			vecB[i+1]=0;
		}
	}
	bool flag = false;
	for(size_t i =0 ;i<N;i++)
	{
		// cout<<vecA[i]<<" "<<vecB[i]<<endl;
		if (vecA[i] != 0)
		{
			flag = true;
		}
	}
	if (flag == true)
	{
		return -1;
	}
	return necessary_sum;

}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		// cout<<T;
		int N;
		cin>>N;
		std::vector<int> vecA(N),vecB(N);

		for (size_t i =0 ;i< N ;i++)
			cin>>vecB[i];
		for (size_t i =0 ;i< N ;i++)
			cin>>vecA[i];
		cout<<add_match(vecA,vecB)<<endl;
	}
}