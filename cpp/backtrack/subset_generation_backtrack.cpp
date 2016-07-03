/*input
4
*/
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#define MAXN 100
using namespace std;

int generate_candidates (bool (&candidates)[2], int &ncandidates)
{	ncandidates=0;
	candidates[0]=true;
	candidates[1]=false;
	ncandidates+=2;
}

int backtrack_subset_generation(bool (&arr)[MAXN],int k, int n)
{	bool candidates[2];
	int ncandidates;
	if (k==n-1)
	{	
		cout<<"{";
		for (int i=0;i<n;i++)
		{	
			if(arr[i])
				cout<<i<<",";

		}
		cout <<"}"<<endl;
	}
	else
	{
		k++;
		generate_candidates(candidates,ncandidates);
		for (int i=0;i<ncandidates;i++)
		{	
			// cout<<k<<i<<candidates[i]<<endl;
			arr[k]=candidates[i];
			// cout<<k<<i<<endl;
			backtrack_subset_generation(arr,k,n);
		}


	}
}

int main()
{
	int n;
	cin>>n;
	bool arr[MAXN];
	backtrack_subset_generation(arr,-1,n);

}