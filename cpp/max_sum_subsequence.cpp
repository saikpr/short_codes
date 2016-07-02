/*input
9
−2 1 −3 4 −1 2 1 −5 4
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cassert>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;
#define MAX_VALUE 100

int max_sum_kadane(std::vector<int> &vec)
{
	int n = vec.size();
	assert(n>0);
	int max_sum_end_here = vec[0], index_count =0, max_index=0;
	int max_sum = 0;
	for(size_t i =1 ;i < n;i++)
	{
		max_sum_end_here += vec[i];
		// cout<<i<<max_sum_end_here<<vec[i]<<endl;
		index_count++;
		if(max_sum_end_here<vec[i])
			{   
				// cout<<i<<endl;
				index_count = 1;
				max_sum_end_here = vec[i];
			}
		if(max_sum_end_here>max_sum)
		{

			max_index = index_count;
			max_sum = max_sum_end_here;
			// cout<<"max_sum"<<max_sum<<index_count<<endl;
		}
	}
	return max_index;
}


int main()
{
	int N,temp;
	cin>>N;
	std::vector<int> numbers_value;
	while(N--)
	{
		cin>>temp;
		numbers_value.push_back(temp);
	}
	cout<<max_sum_kadane(numbers_value);
}