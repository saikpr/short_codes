/*input
7
4 7 7 7 8 10 10 
3
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

int binary_search ( const vector<int> &A,int B, int low, int high)
{
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		// cout<<low<<" "<<mid<<" "<<high<<" "<<B;
		if (A[mid] == B)
			return mid;
		else if (A[mid]<B)
		{
			low = mid+1;
		}
		else
			high=mid -1;
	}
	return -1;
}


vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> to_return;
    // cout<<A.size();
    int index = binary_search(A,B,0,A.size()-1);
    // cout<<index<<endl;
    if (index == -1)
    	{to_return.push_back(-1);to_return.push_back(-1);return to_return;}
    int upper_index = index ,lower_index = index;
    int upper_index_prev, lower_index_prev;
    while ( upper_index<=A.size()-1)
    {
    	upper_index_prev = binary_search(A,B,upper_index+1,A.size()-1);
    	// cout<<upper_index_prev<<endl;
    	if (upper_index_prev==-1)
    		break;
    	upper_index = upper_index_prev;
    }
    while ( lower_index>=0)
    {
    	lower_index_prev = binary_search(A,B,0,lower_index-1);
    	if (lower_index_prev==-1)
    		break;
    	lower_index = lower_index_prev;
    }
    // cout<<lower_index<<upper_index<<endl;
    to_return.push_back(lower_index);to_return.push_back(upper_index);
    return to_return;
}



int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for (size_t i = 0; i < n;i++)
	{
		cin>>vec[i];
	}
	int B;
	cin>>B;
	vector<int> tmp = searchRange(vec,B);
	cout<<tmp[0]<<" "<<tmp[1]<<endl;
	// for (size_t i = 0; i < n;i++)
	// {
	// 	cout<<vec[i]<<" "<<sqrt(vec[i])<<endl;
	// }
	// cout<<sqrt(308634616)<<endl;

}
