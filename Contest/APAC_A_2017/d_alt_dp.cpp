/*input
1
967 8
2 2
783 955
22
2 2
315 617
28
3 2
517 770 801
18 7
10 1
126 145 147 181 254 263 510 649 888 906
11 28 15 27 31 17 7 28 29
2 2
442 542
22
4 1
435 645 853 946
6 20 29
1 1
906

7 2
101 178 190 269 393 584 832
22 12 14 21 30 8
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <deque>

using namespace std;
const int MAX_INT = (int)(~0U>>1);

int calculate_max_activity(vector<deque <pair<int,int>> > &card_activity_and_price,  int W)
{
	int N_coins = card_activity_and_price.size();
	std::vector<std::vector<int> > state_space(W+1,vector<int>(N_coins,0));
	for(size_t i =0 ;i<card_activity_and_price[0].size();i++)
	{
		state_space[card_activity_and_price[0][i].second][0]=card_activity_and_price[0][i].first;
	}
	int temp = state_space[0][0];
	for(size_t i =0 ;i<=W;i++)
	{
		if(state_space[i][0]!=0)
		{
			temp = state_space[i][0];
		}
		state_space[i][0]=temp;
	}
	for(size_t i =0 ;i<N_coins;i++)
	{
		state_space[0][i]=card_activity_and_price[i][0].first;
	}
	for(size_t i =1 ;i<N_coins;i++)
	{
		state_space[0][i]+=state_space[0][i-1];
	}
	
	
	for(size_t j =1 ;j<N_coins;j++)
	{	
		
		for(size_t i =1 ;i<=W;i++)
		{
			int max_val=0;
			for(size_t k =0;k<card_activity_and_price[j].size();k++)
			{
				if(i>=card_activity_and_price[j][k].second)
				max_val = max(max_val,card_activity_and_price[j][k].first+state_space[i-card_activity_and_price[j][k].second][j-1]);
				// if(max_val ==card_activity_and_price[j][k].first+state_space[i-card_activity_and_price[j][k].second][j-1])
				// {
				// 	// cout<<i<<" "<<j<<" "<<max_val<<" "<<card_activity_and_price[j][k].first<<" "<<state_space[i-card_activity_and_price[j][k].second][j-1]<<endl;
				// }
			}
			state_space[i][j]=max_val;
			// cout<<i<<" "<<j<<" "<<max_val<<endl;
		}
	}

	// for(size_t j =0 ; j<W+1;j++)
	// {
	// 	for(size_t k =0 ; k<N_coins;k++)
	// 	{
	// 		cout<<state_space[j][k]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return state_space[W][N_coins-1];
}	

int main ()
{
	int T;
	cin>>T;
	int temp;
	// cout<<MAX_INT;
	for(size_t t=0;t<T;t++)
	{
		int N_coins, M_max;
		cin>>M_max>>N_coins;
		vector<int> card_levels(N_coins);
		vector<deque <pair<int,int> > > card_activity_and_price(N_coins);
		// vector < deque<int> > card_activity_level(N_coins);
		int init_sum =  0;
		for(size_t each_coin =0; each_coin<N_coins;each_coin++)
		{
			int max_level,coin_level;
			cin>>max_level>>coin_level;
			// cout<<"max_level "<<max_level<<"coin_level"<<coin_level<<endl;
			card_levels[each_coin]=coin_level;
			for(size_t each_level =0 ; each_level<max_level;each_level++)
			{
				cin>>temp;
				// if(each_level+1>max_level)
					card_activity_and_price[each_coin].push_back(make_pair(temp,0));
			}
			// while(card_levels[each_coin]!=1)
			// {
			// 	card_activity_and_price[each_coin].pop_front();
			// 	card_levels[each_coin]--;
			// 	// cout<<"y";
			// }
			// cout<<card_activity_and_price[each_coin].size()<<endl;
			if(max_level!=1)
				for(size_t each_level =1; each_level<max_level;each_level++)
				{
					cin>>temp;
					// cout<<temp<<" "<<each_level<<endl;
					card_activity_and_price[each_coin][each_level].second = temp;

				}


		}
		// for(size_t j =0 ; j<N_coins;j++)
		// {
		// 	for(size_t k =0 ; k<card_activity_and_price[j].size();k++)
		// 	{
		// 		cout<<j<<" "<<k<<" "<<card_activity_and_price[j].size()<<" "<<card_activity_and_price[j][k].first<<" "<<card_activity_and_price[j][k].second<<endl;
		// 	}
		// }
		// cout<<M_max<<N_coins<<endl;
		// for(size_t ind_i =0 ; ind_i <card_levels.size();ind_i++ )
		// {
		// 	cout<<card_levels[ind_i]<<",";
		// }
		// cout<<endl;
		for(size_t ind_i =0 ; ind_i <card_levels.size();ind_i++ )
		{

			while(card_levels[ind_i]!=1)
			{
				card_activity_and_price[ind_i].pop_front();
				card_levels[ind_i]--;
				// cout<<"y";
			}
		}
		for(size_t j =0 ; j<N_coins;j++)
		{	
			card_activity_and_price[j][0].second=0;
			for(size_t k =1 ; k<card_activity_and_price[j].size();k++)
			{
				card_activity_and_price[j][k].second = card_activity_and_price[j][k].second+card_activity_and_price[j][k-1].second;
			}
		}
		// for(size_t j =0 ; j<N_coins;j++)
		// {
		// 	for(size_t k =0 ; k<card_activity_and_price[j].size();k++)
		// 	{
		// 		cout<<j<<" "<<k<<" "<<card_activity_and_price[j].size()<<" "<<card_activity_and_price[j][k].first<<" "<<card_activity_and_price[j][k].second<<endl;
		// 	}
		// }

		// cout<<"init_sum "<<init_sum<<endl;
		cout<<"Case #"<<t+1<<": ";
		cout<<calculate_max_activity(card_activity_and_price,M_max)<<endl;
		
	}
}