/*input
3
1 2 3
4

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
	{	cout<<i<< " ";
		for (size_t j =0 ;j <m;j++)
		{
			cout<<vec[i][j]<<" " ;
		}
		cout<<endl;
	}
}

int  coins_count (std::vector<int> &coin_deno, int value)
{
	int n = coin_deno.size();
	std::vector<vector <int>> coin_state_space(value+1,std::vector<int>(n,0));

	fill(coin_state_space[0].begin(),coin_state_space[0].end(),1);
	for(size_t i=0;i<=value;i++)
	{
		if(i%coin_deno[0]==0)
		coin_state_space[i][0]=1;
	}
	
	for(int i=1;i<=value;i++)
	{
		for(int j=1;j<n;j++)
		{
			if ((i-coin_deno[j])>0)
			{
				coin_state_space[i][j] = coin_state_space[(i-coin_deno[j])][j]+coin_state_space[i][j-1];
			}
			else if ((i-coin_deno[j])==0)
			{
				coin_state_space[i][j] = 1+coin_state_space[i][j-1];
			}else
			{
				coin_state_space[i][j] = coin_state_space[i][j-1];
			}
		}
	}

	// print_vec(coin_state_space);
	return coin_state_space[value][n-1];
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
	int value;
	cin>> value;
	cout<<coins_count(v,value);
}