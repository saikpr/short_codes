/*input
3 4
*/#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#include <utility>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int bits_count (int A)
{
	assert(A>=0);
	int val = 0 ; 
	for(size_t i =  0 ; i  < 31 ; i ++)
	{
		if ( (1<<i )&A)
			val = i;
	}
	return val+1;
}

int divide_int(int A, int B)
{
	int b_A = 0 ;
	int b_B = 0;
	int result = 0 , temp = 0;
	b_A = bits_count(A);
	b_B = bits_count(B);
	// cout<<b_A<<" "<<b_B<<endl;
	while(b_A)
	{
		// cout<<A<<" "<<temp<<" "<<result<<endl;
		// cout<<(A>>(b_A-1))<<endl;
		temp = (temp<<1) | (A>>(b_A-1));
		A = (~((~0)<<(b_A-1)))&A;
		b_A--;
		if (temp>=B)
		{
			// cout<<"Here"<<endl;
			result = (result<<1 )|1;
			temp-=B;
		}
		else
		{
			result = result<<1;
		}
	}
	return result;

}

int main()
{
	int A, B;
	cin>>A>>B;
	vector<int> vec({1,2});
	// map<vector<int>, int> mp;
	// mp[vec]=232;
	// cout<<mp[vector<int>({1,2})]<<endl;
	cout<<divide_int(A,B);
}