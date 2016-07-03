/*input
6
1 2 3 4 5 6 7 8 9 10
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


int sum_of_vector(std::vector<int> &vec)
{
	int sum_val = 0;
	for(size_t i =0 ; i< vec.size();i++)
	{
		sum_val +=vec[i];
	}
	return sum_val;
}
void print_vector(std::vector<int> &vec,vector<int> &bracket_candidates)
{
	// int sum_val = 0;
	int start_index=0,end_index=0;
	for(size_t i =0 ; i< vec.size();i++)
	{
		start_index = end_index;
		end_index = start_index+vec[i];
		cout<<"(";
		for(size_t j = start_index;j<end_index;j++)
		{
			cout<<bracket_candidates[j];
			if(j!=end_index-1)
				cout<<",";
		}
		cout<<")";
	}
	return ;
}
void interger_partition_backtrack(int n,  vector<int> &candidate,vector<int> &bracket_candidates)
{	
	int k =sum_of_vector(candidate);

	if (k==n)
	{
		print_vector(candidate,bracket_candidates);
		cout<<endl;
	}
	else if (k>n)
	{
		return;
	}
	else
	{
		std::vector<int > possible_candidates;
		for(int i =1;i<=(n-k);i++)
		{
			possible_candidates.push_back(i);
		}

		for(size_t i =0 ; i < possible_candidates.size();i++)
		{
			candidate.push_back(possible_candidates[i]);
			interger_partition_backtrack(n,candidate,bracket_candidates);
			candidate.pop_back();
		}

	}
}

int main()
{
	int n;
	cin>>n;
	std::vector<int> candidate,bracket_candidates(n);
	for(size_t i =0 ;i < n; i++)
	{
		cin>>bracket_candidates[i];
	}
	interger_partition_backtrack(n,	 candidate,bracket_candidates);
}