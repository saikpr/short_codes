/*input
9
1 2 3 4 5 6 7 8 9
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

void print_vec ( std::vector<std::vector<int> > &vec)
{
	int n=vec.size();
	
	int m=vec[0].size();
	// cout<<n<<endl;
	for(size_t i =0; i<n;i++)
	{
		for (size_t j =0 ;j <m;j++)
		{
			cout<<vec[i][j]<<" " ;
		}
		cout<<endl;
	}
}

int partition_dp (std::vector<int> &vec, int K)
{
	int n= vec.size();
	vector <std::vector<int> > state_space(K+1,std::vector<int>(n+1,0)),partition(K+1,std::vector<int>(n+1,0));
	std::vector< int > prefix_sum(n+1);
	prefix_sum[1]=vec[0];

	for (size_t i =2; i<=n ;i++)
	{
		prefix_sum[i]=prefix_sum[i-1]+vec[i-1];
		// cout<<prefix_sum[i];
	}
	for (size_t i =0; i<=n ;i++)
	{
		state_space [1][i]=prefix_sum[i];
	}

	int this_val, overall_val, part_index ;
	for (size_t i =0; i<=K ;i++)
	{
		state_space [i][1]= vec[0];
	}

	for(size_t i =2 ; i<=K;i++)
	{
		for(size_t j =2; j<=n;j++)
		{	
			overall_val = 100000;
			part_index = -1;
			for(size_t ind_k=1;ind_k<=j;ind_k++)
			{
				this_val = max(state_space[i-1][ind_k],prefix_sum[j]-prefix_sum[ind_k]);
				if(overall_val>this_val)
				{
					overall_val = this_val;
					part_index = ind_k;

				}
				// else
				// 	{partition[ind_k]=0;}
				// overall_val = min (overall_val,this_val);
			}
			state_space[i][j]=overall_val;
			partition[i][j]=part_index;
		}
	}
	int val_k = K,val_n=n;
	// cout<<partition[K][val_n]<<endl;
	while(val_k>1)
	{
		cout<<"Partition at"<<partition[val_k][val_n]<<endl;
		val_n = partition[val_k][val_n ];
		// cout<<val_n<<val_k<<endl;
		val_k--;

	}
	// print_vec(partition);
	// cout<<"state_space"<<endl;
	// print_vec(state_space);


}


int main ()
{
	int N;
	cin>>N;
	std::vector< int > v;
	// v.resize(N);
	int temp;
	while(N-->0)
	{
		cin>>temp;
		v.push_back(temp);
	}
	// cout<<"here"<<endl;
	partition_dp(v, 3);
}