/*input
6
9 8 7 6 4 3
*/
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;
int quick(vector<int> &arr,int low, int high)
{
	if(low>=high)
	return arr[low];
	
	int pivot = arr[low];
	int index = low+1;
	int sep = low+1;
	while(index<=high)
	{
		if(arr[index]<=pivot)
		{
			swap(arr[index],arr[sep]);
			sep++;
		}
		index++;
	}
	swap(arr[sep-1],arr[low]);
	return sep-1;
}
void printvec(vector<int> &vec)
{
	for(size_t i = 0 ; i < vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

void quicksort(vector<int> &arr, int low, int high)
{
	if(low>=high)
		return ;
	int pivot = quick(arr,low,high);
	quicksort(arr,low,pivot-1);
	quicksort(arr,pivot+1,high);
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0 ; i < n ;  i++)
	{
		cin>>nums[i];
	}
	printvec(nums);
	quicksort(nums,0,n-1);

	printvec(nums);
}