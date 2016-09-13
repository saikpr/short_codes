/*input
2
20 8
3 1
1 10 100
1 2
3 1
1 10 100
1 3
3 1
1 10 100
1 4
3 1
1 10 100
1 5
3 1
1 10 100
1 6
3 1
1 10 100
1 7
3 1
1 10 100
1 8
3 1
1 10 100
1 9
30 10
4 1
1 10 100 200
1 2 3
3 1
1 10 100
2 4
3 1
1 10 100
3 6
4 2
1 10 100 200
4 8 16
3 1
1 10 100
5 10
3 1
1 10 100
6 12
3 1
1 10 100
7 14
3 1
1 10 100
8 16
3 1
1 10 100
9 18
3 1
1 10 100
10 20
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
#include <map>
#include <deque>

using namespace std;
const long long int MAX_INT = (int)(~0U>>1);
string next_largest(string &str)
{
	int n= str.size();
	string new_str;
	int max_i = -1, max_j = -1;
	for (size_t i = 0 ; i< n ; i++)
	{
		if(str[i]<str[i+1])
			max_i = i;
	}
	// cout<<max_i;
	if (max_i ==-1)
		return new_str;
	for(size_t j = max_i; j<n;j++)
	{
		if (str[max_i]<str[j])
			max_j = j;
	}
	new_str = str; //copy(str.begin(),str.end(),new_str.begin())
	swap(new_str[max_i],new_str[max_j]);
	reverse(new_str.begin()+max_i+1,new_str.end());
	// cout<<max_i<<max_j<<endl;
	return new_str;
}
vector<deque <pair<long long int,long long int>> > generate_deque(vector<deque <pair<long long int,long long int>> > &original, string str)
{
	vector<deque <pair<long long int,long long int>> > temp;

	for(size_t i =0; i <str.size();i++)
	{
		if (str[i]=='1')
			temp.push_back(original[i]);
	}
	return temp;
}
long long int calculate_max_activity(vector<deque <pair<long long int,long long int>> > &card_activity_and_price,  long long int W, string &str)
{
	// long long int N_coins = card_activity_and_price.size();
	
	map < long long int, long long int> u_map,u_map_2;
	long long int sum_activity,sum_price;
	vector<int> index;
	for(size_t i =0 ; i < str.size();i++)
	{
		if(str[i]=='1')
			index.push_back(i);
	}
	for(size_t ind_i =0 ;ind_i<card_activity_and_price[index[0]].size();ind_i++)
	{
		for(size_t ind_j =0 ;ind_j<card_activity_and_price[index[1]].size();ind_j++)
		{
			for(size_t ind_k =0 ;ind_k<card_activity_and_price[index[2]].size();ind_k++)	
			{
				for(size_t ind_l =0 ;ind_l<card_activity_and_price[index[3]].size();ind_l++)
				{
					sum_activity = card_activity_and_price[index[0]][ind_i].first+
									card_activity_and_price[index[1]][ind_j].first +
									card_activity_and_price[index[2]][ind_k].first+
									card_activity_and_price[index[3]][ind_l].first;
					
					sum_price = card_activity_and_price[index[0]][ind_i].second+
									card_activity_and_price[index[1]][ind_j].second +
									card_activity_and_price[index[2]][ind_k].second+
									card_activity_and_price[index[3]][ind_l].second;
					 
					if(sum_activity> u_map[sum_price])
					u_map[sum_price] = sum_activity;
					
					if (u_map[sum_price] ==0)
					cout<<sum_price<<sum_activity<<endl;  
				}
			}
		}
	}
	
	
	for(size_t ind_i =0 ;ind_i<card_activity_and_price[index[4+0]].size();ind_i++)
	{
		for(size_t ind_j =0 ;ind_j<card_activity_and_price[index[4+1]].size();ind_j++)
		{
			for(size_t ind_k =0 ;ind_k<card_activity_and_price[index[4+2]].size();ind_k++)	
			{
				for(size_t ind_l =0 ;ind_l<card_activity_and_price[index[4+3]].size();ind_l++)
				{
					sum_activity =  card_activity_and_price[index[4+0]][ind_i].first+
									card_activity_and_price[index[4+1]][ind_j].first +
									card_activity_and_price[index[4+2]][ind_k].first+
									card_activity_and_price[index[4+3]][ind_l].first;
					
					sum_price = 	card_activity_and_price[index[4+0]][ind_i].second+
									card_activity_and_price[index[4+1]][ind_j].second +
									card_activity_and_price[index[4+2]][ind_k].second+
									card_activity_and_price[index[4+3]][ind_l].second;
					
					if(sum_activity> u_map_2[sum_price])
					u_map_2[sum_price] = sum_activity;

				}
			}
		}
	}

	vector < pair<long long int,long long int> >  vec, vec_2 ;
	bool flag=false;
	long long int temp;
	for (map<long long int,long long int>::iterator it =u_map.begin();it!= u_map.end();it++ )
	{
		if(flag == true)
		{
			if(it->second<=temp)
			{
				continue;
			}
		}
		if(it->second!=0)
		{
			flag = true;
			vec.push_back(*it);
			temp = it->second;
		}

	}
	flag =false;
	for (map<long long int,long long int>::iterator it =u_map_2.begin();it!= u_map_2.end();it++ )
	{
		if(flag == true)
		{
			if(it->second<=temp)
			{
				continue;
			}
		}
		if(it->second!=0)
		{
			flag = true;
			vec_2.push_back(*it);
			temp = it->second;
		}

	}
	long long int max_activity = 0;
	// for(size_t ind_vec =0; ind_vec<vec.size();ind_vec++)
	// 	cout<<vec[ind_vec].first<<"v"<<vec[ind_vec].second<<" ";
	// cout<<endl;
	// for(size_t ind_vec =0; ind_vec<vec_2.size();ind_vec++)
	// 	cout<<vec_2[ind_vec].first<<"e"<<vec_2[ind_vec].second<<" ";
	// cout<<endl;
	

	for(size_t ind_i =0; ind_i<vec.size();ind_i++)
	{
		// int high = vec_2.size()-1, low=0;
		// while(low<=high)
		// {
		// 	int mid = high +low;
		// 	if(vec[ind_i].first +vec_2[mid].first>W )
		// 	{
		// 		high = mid -1;
		// 	}
		// 	else if (vec[ind_i].first +vec_2[mid].first<W )
		// 	{
		// 		low= mid+1;
		// 		max_activity = max(max_activity,vec[ind_i].second+vec_2[mid].second);
		// 	}
		// 	else
		// 	{
		// 		max_activity = max(max_activity,vec[ind_i].second+vec_2[mid].second);
		// 		break;
		// 	}
		// }
		for(size_t ind_j =0;ind_j < vec_2.size();ind_j++)
		{
			if(vec[ind_i].first+vec_2[ind_j].first>W)
				break;
			max_activity = max(max_activity,vec[ind_i].second+vec_2[ind_j].second);
		}
	}
	return max_activity;
}	

int main ()
{
	long long int T;
	cin>>T;
	long long int temp;
	// cout<<MAX_long long int;
	for(size_t t=0;t<T;t++)
	{
		long long int N_coins, M_max;
		cin>>M_max>>N_coins;
		vector<long long int> card_levels(N_coins);
		vector<deque <pair<long long int,long long int> > > card_activity_and_price(N_coins);
		// vector < deque<long long int> > card_activity_level(N_coins);
		long long int init_sum =  0;
		for(size_t each_coin =0; each_coin<N_coins;each_coin++)
		{
			long long int max_level,coin_level;
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
		

		// cout<<"init_sum "<<init_sum<<endl;
		string str;
		for(size_t i =0;i<N_coins - 8;i++)
		{
			str= str+ string("0");
		}
		for(size_t i =0;i< 8;i++)
		{
			str= str+string("1");
		}
		// cout<<str<<endl;
		// cout<<next_largest(str)<<endl;
		// for(size_t j =0 ; j<N_coins;j++)
		// {
		// 	for(size_t k =0 ; k<card_activity_and_price[j].size();k++)
		// 	{
		// 		cout<<j<<" "<<k<<" "<<card_activity_and_price[j].size()<<" "<<card_activity_and_price[j][k].first<<" "<<card_activity_and_price[j][k].second<<endl;
		// 	}
		// }
		long long int max_act = 0;

		while(str.empty()==false)
		{
			// cout<<str<<endl;
			// vector<deque <pair<long long int,long long int>> > new_deque = generate_deque(card_activity_and_price,str);
			
			max_act = max(max_act,calculate_max_activity(card_activity_and_price,M_max,str));
			str = next_largest(str);
		}
		cout<<"Case #"<<t+1<<": ";
		cout<<max_act<<endl;
		// cout<<calcula/te_max_activity(card_activity_and_price,M_max)<<endl;
		
	}
}