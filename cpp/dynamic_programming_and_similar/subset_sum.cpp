/*input
6
3 34 4 12 5 2
*/
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100
using namespace std;

int subset_sum(vector<int> &vec, int sum_val)
{
	int n =vec.size();
	vector<int> sum_c(sum_val+1,-1);
	sum_c[0]=0;

	sort(vec.begin(),vec.end());

	for(size_t i = 0 ; i<n;i++)
	{
		for(int j = sum_val; j>=0 ;j--)
		{	
			// cout<<j+vec[i]<<endl;
			if (sum_c[j]!= -1 && j+vec[i]<=sum_val)
			{
				if(sum_c[j+vec[i]]==-1)
				{
					sum_c[j+vec[i]] = sum_c[j]+1;
				}
				else
				{
					sum_c[j+vec[i]] = min(sum_c[j+vec[i]],sum_c[j]+1);
				}
			}
		}
		for(size_t j = 1; j<=sum_val;j++)
		{
			cout<<sum_c[j]<<" ";
		}
		cout<<endl;
	}
	for(size_t j = 1; j<=sum_val;j++)
	{
		cout<<sum_c[j]<<" ";
	}
	return sum_c[10];
}

int main()
{
	int n;
	cin>>n;
	std::vector<int > vec(n);

	for(size_t i =0;i<n;i++)
		cin>>vec[i];
	cout<<endl<<subset_sum(vec,22);
}