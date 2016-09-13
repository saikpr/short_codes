/*input
5
10
1 2 9 15 25
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <cassert>
#include <cstdlib>
#include <math.h>
using namespace std;

// int abs(int a , int b)
int find_min_distance(vector<int> &vec,int K)
{
	assert(vec.size()>0);
	int low=0,high=vec.size()-1,mid=-1;
	int min_val = 1000000;
	while(low<high)
	{
		mid = (low+high)/2;
		cout<<low<<" "<<mid<<" "<<high<<endl;
		min_val = min(min_val,abs(K-vec[mid]));
		if((K-vec[mid])*(K-vec[low])<0)
		{
			high = mid -1;
		}
		else if ((K-vec[mid])*(K-vec[high])< 0)
		{
			low = mid +1;

		}
		else
		{
			// cout<<"thisca";
			break;
		}
	}
	min_val = min(min_val,abs(K-vec[high]));
	min_val = min(min_val,abs(K-vec[low]));
	return (min_val);

}

int main()
{
	int N;
	cin>>N;
	int min_k;
	cin>>min_k;
	std::vector<int> vec(N);
	for(size_t i =0 ;i<N;i++)
	{
		cin>>vec[i];
	}
	cout<<find_min_distance(vec,min_k);

}