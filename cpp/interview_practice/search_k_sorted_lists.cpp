/*input
9
-50 -42 -38 1 4 9 16 33 47 
1
-44 
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


int sequencial_find(const vector<int> &A, const vector<int> &B,int low1,int low2, int high1, int high2,int k)
{

	int index1 = low1;
	int index2 = low2;
	while(k>1&&index1<=high1 && index2<= high2)
	{
		if (A[index1]<B[index2])
			index1++;
		else
			index2++;
		k--;
	}
	cout<<high1<<" "<<high2<<" "<<index1<<" "<<index2<<" "<<low1<<" "<<low2<<" "<<k<<endl;
	 if(k==1&&index1<=high1 && index2<=high2)
	 {
	 	if (A[index1]<B[index2])
	 		return A[index1];
	 	else
	 		return B[index2];
	 }
	 else if (index1<=high1 && k<=high1-index1+1)
	 {
	 	return A[index1+k-1];
	 }
	 else if (index2<=high2 && k<=high2-index2+1)
	 {
	 	return B[index2+k-1];

	 }
	return -1;
}


int find_helper(const vector<int> &A, const vector<int> &B,int low1,int high1, int low2, int high2,int k)
{
	// cout<<low1<<"                                   "<<low2<<" "<<high1<<" "<<high2<<" "<<k<<endl;
	if (k<=3)
	{

		return sequencial_find(A,B,low1,low2,high1 ,high2,k);
	}
	// if(k==0)
	// {
	// 	cout<<A[low1]<<" "<<B[low2]<<endl;
	// }
	// high1 = min(high1,k);
	// high2 = min(high2,k);
	int mid1 = 0;
	int mid2 = 0;
	if (k/2 > high1 - low1)
	{
		mid1 = high1;
	}
	else
	{
		mid1 = low1+(k-1)/2;
	}
	if (k/2 > high2 - low2)
	{
		mid2 = high2;
	}
	else
	{
		mid2 = low2+(k-1)/2 ;
	}
	cout<<low1<<" "<<low2<<" "<<high1<<" "<<high2<<" "<<mid1<<" "<<mid2<<" "<<k<<endl;
	// if (mid1==low1)
	// {
	// 	return find_helper(A,B,0, low1,0,mid2-1,k-mid1-1);
	// }
	if (A[mid1]==B[mid2])
	{
		return A[mid1];
	}
	else
	if (A[mid1]>B[mid2])
	{
		// if(k-mid2-1>0)
			return find_helper(A,B,low1, mid1,mid2,high2,k-(mid2-low2));
		// else
		// 	return find_helper(A,B,low1, low1+1,mid2+1,mid2+2,1);
	}
	else if (A[mid1]<B[mid2])
	{
		// if(k-mid1-1>0)
			return find_helper(A,B,mid1,high1,low2,mid2,k-(mid1-low1));
		// else
		// 	return find_helper(A,B,mid1+1,mid1+2,low2,low2+1,1);
	}
	


}
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
   
		// cout<<sequencial_find(A,B,5,3,5,5,4)<<endl;
    // for(size_t i =0 ;i<A.size()+B.size();i++)
    // 	cout<<i+1<<" "<<find_helper(A,B,0,A.size()-1,0,B.size()-1,i+1)<<endl;
    int size_val = (A.size()+B.size());
    // cout<<size_val;
    double val_1,val_2;
    if (A.size()==0)
    {
        if (B.size()%2==1)
            return B[B.size()/2];
        else
        {
         val_1 =    B[B.size()/2-1];
         val_2 =    B[B.size()/2];
         return (val_2+val_1)/2;
        }
    }
    else if (B.size()==0)
    {
        if (A.size()%2==1)
            return A[A.size()/2];
        else
        {
         val_1 =    A[A.size()/2-1];
         val_2 =    A[A.size()/2];
        }
    }
    else if (size_val%2==1)
    {
    	return find_helper(A,B,0,A.size()-1,0,B.size()-1,size_val/2+1);
    }
    else
    {
    	val_1 = find_helper(A,B,0,A.size()-1,0,B.size()-1,size_val/2);
    	val_2 = find_helper(A,B,0,A.size()-1,0,B.size()-1,size_val/2+1);
    }
    return (val_2+val_1)/2;
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

	int m;
	cin>>m;
	// cout<<m<<endl;
	vector<int> vec2(m);
	for (size_t i = 0; i < m;i++)
	{
		cin>>vec2[i];
	}

	cout<<findMedianSortedArrays(vec,vec2);

}
