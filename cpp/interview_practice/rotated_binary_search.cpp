/*input
122
180 181 182 183 184 187 188 189 191 192 193 194 195 196 201 202 203 204 3 4 5 6 7 8 9 10 14 16 17 18 19 23 26 27 28 29 32 33 36 37 38 39 41 42 43 45 48 51 52 53 54 56 62 63 64 67 69 72 73 75 77 78 79 83 85 87 90 91 92 93 96 98 99 101 102 104 105 106 107 108 109 111 113 115 116 118 119 120 122 123 124 126 127 129 130 135 137 138 139 143 144 145 147 149 152 155 156 160 162 163 164 166 168 169 170 171 172 173 174 175 176 177
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

int search_helper(const vector<int> &A, int B, int low, int high)
{

    // cout<<low<<" "<<high<<" " <<A[low]<<" "<<A[(high+low)/2]<<" "<<A[high]<<endl;
    if(low>high)
	    return -1;
    if (low==high)
    {
        if (A[low]==B)
            return low;
        else
            return -1;
    }
    bool found=false;
    if (A[low]==B)
    {
        return low;
    }
    int mid = (high+low)/2;
    if (A[mid]==B)
    	return mid;
    if(A[low]<=B && B<A[mid])
    {
    	return binary_search(A,B,low,mid-1);
    }
    else if (A[mid]<B && B<=A[high])
    {
    	return binary_search(A,B,mid+1,high);
    }
    else if (A[low]<B && A[low]>A[mid])
    {
    	return search_helper(A,B,low,mid-1);
    }
    else if (A[low]<B && A[low]<A[mid])
    {
    	return search_helper(A,B,mid+1,high);
    }
    else if (A[low]>B && A[high]<A[mid])
    {
    	return search_helper(A,B,mid+1,high);
    }
    else if (A[low]>B && A[high]>A[mid])
    {
    	return search_helper(A,B,low,mid-1);
    }
    return -1;
}
int search(const vector<int> &A, int B) {
    return search_helper(A,  B,  0,  (int)(A.size()-1)) ;
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

	// for(int i =0 ;i<24;i++)
	// {
		cout<<search(vec,42)<<endl;
	// }
}