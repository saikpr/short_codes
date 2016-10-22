/*input
3
2 5 10
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <climits>
using namespace std;
#define MAX_VALUE 10000

vector<int> fibo_sum_dp(vector<int> &fibo)
{
	vector<int> fibo_sum(MAX_VALUE,INT_MAX);

	for(size_t i =0 ; i < fibo.size() && fibo[i]<MAX_VALUE;i++)
	{
		fibo_sum[fibo[i]] =1;
	}
	// cout<<"here"<<endl;
	for(size_t i = 4 ; i < fibo_sum.size();i++)
	{
		if(fibo_sum[i]==1)
			continue;
		for(size_t j =0 ; j < fibo.size();j++)
		{
			if(fibo[j]>i)
				break;
			fibo_sum[i] = min (fibo_sum[i],1+fibo_sum[i-fibo[j]]);			
		}
	}
	return fibo_sum;

}
int count_greedy(int val,vector<int> &fibo)
{
	int count=0;
	while(val!=0)
	{
		size_t i;
		for( i = 0 ; i < fibo.size() && fibo[i]<=val;i++)
		{

		}
		i--;
		val -=fibo[i];
		count++;
	}
	return count;
}
vector<int> fibo_sum_greedy(vector<int> &fibo)
{
	vector<int> fibo_sum(MAX_VALUE,INT_MAX);

	for(size_t i =0 ; i < fibo.size() && fibo[i]<MAX_VALUE;i++)
	{
		fibo_sum[fibo[i]] =1;
	}
	// cout<<"here"<<endl;
	for(size_t i = 4 ; i < fibo_sum.size();i++)
	{
		if(fibo_sum[i]==1)
			continue;
		fibo_sum[i] = count_greedy(i,fibo);
	}
	return fibo_sum;

}
int main()
{
	vector<int> fibo(50);
	fibo[0]=1;
	fibo[1]=1;
	for(size_t i = 2 ;i < fibo.size();i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	cout<<fibo[48]<<endl;

	std::vector<int> vec_dp =fibo_sum_dp(fibo) ;
	// cout<<vec_dp[9999]<<endl;
	std::vector<int> vec_greedy =fibo_sum_greedy(fibo) ;
	// cout<<vec_greedy[9999]<<endl;
	for(size_t i =0 ; i < vec_dp.size();i++)
	{
		if (vec_greedy[i]!=vec_dp[i])
			cout<<i<<" "<<vec_dp[i]<<" "<<vec_greedy[i]<<endl;
	}
	cout<<vec_dp[2583]<<endl;

}