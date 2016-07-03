/*input
3
2 5 10
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;
#define MAX_VALUE 100

int coin_denomination(std::vector<int> &coins_vec, int value)
{
	std::vector<int> coin_state_space(MAX_VALUE,-1);

	for (int i =0 ; i< coins_vec.size();i++)
	{
		coin_state_space[coins_vec[i]]=1;
	}
	int min_coin_count=-1;
	bool flag;
	// cout<<coin_state_space[0];
	for(int i =0 ; i<coin_state_space.size();i++)
	{
		if (coin_state_space[i]==-1&&i>coins_vec[0])
		{	min_coin_count = 182666;
			flag =false;
			for(int j =0; j<coins_vec.size();j++)
			{	
				// cout<<i<<" "<<j<<" "<<(i-coins_vec[j])<<" "<<coin_state_space[(i-coins_vec[j])]<<endl;
				if((i-coins_vec[j])>0 && coin_state_space[(i-coins_vec[j])]>0 ) 
				{
					// cout<<i<<" "<<j<<" "<<(i-coins_vec[j])<<" "<<coin_state_space[(i-coins_vec[j])]<<" "<<min_coin_count<<endl;
					min_coin_count = min (min_coin_count,1+coin_state_space[(i-coins_vec[j])]);
					// cout<<min_coin_count<<endl;
					flag =true;
				}
				// 
			}
			if(flag)
			coin_state_space[i] = min_coin_count;
		}
	}
	for(int i =0 ; i<coin_state_space.size();i++)
	{
		cout<<i<<" "<<coin_state_space[i]<<endl;
	}

}

int main()
{
	int N,temp;
	cin>>N;
	std::vector<int> coins;
	while(N--)
	{
		cin>>temp;
		coins.push_back(temp);
	}
	// for(int i =0 ; i< coins.size();i++)
	// 	cout<<coins[i]<<" ";
	coin_denomination(coins,10);
}