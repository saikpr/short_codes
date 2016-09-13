/*input
1
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

int find_sum (vector<deque<pair<int,int>>> &vec,vector<int> &l_i, int M)
{
	int N = vec.size();
	int init_sum=0;

	pair <int,int> best_case;
	int index_bestcase = -1;
	// int temp_best_val = 0;
	while(M >0)
	{
		best_case = make_pair(0,1);
		index_bestcase = -1;
		for(size_t i =0 ; i < N ; i++)
		{	
			// cout<<M<<" "<<i<<" "<<vec[i][0].first*1.0/vec[i][0].second<<" "<<best_case.first*1.0/best_case.second<<endl;
			if(vec[i].size()>0 &&vec[i][0].second<=M&& vec[i][0].first*1.0/vec[i][0].second> best_case.first*1.0/best_case.second )
			{
				// cout<<vec[i][0].first*1.0/vec[i][0].second<<" "<<best_case.first*1.0/best_case.second<<endl;
				best_case = vec[i][0];
				// cout<<"valM"<<M<<" "<<index_bestcase<<" "<<i<<endl;
				index_bestcase = i;

				// cout<<vec[i][0].first*1.0/vec[i][0].second<<" "<<best_case.first*1.0/best_case.second<<endl;
				
			}
			else
			if(vec[i].size()>0 &&vec[i][0].second<=M&& vec[i][0]== best_case )
			{
				int k_i=0;
				int m_i=0;
				int k_j = vec[index_bestcase].size();
				int m_j = vec[i].size();
				while(k_i<k_j&&m_i<m_j)
				{
					// if(k_i==k_j)
					// {
					// 	index_bestcase = i;
					// 	break;
					// }	
					// else if (m_i==m_j)
					// {
					// 	index_bestcase = index_bestcase;
					// 	break;
					// }
					if(vec[index_bestcase][k_i]==vec[i][m_i])
					{
						k_i++;
						m_i++;


					}
					else if(vec[index_bestcase][k_i].first*1.0/vec[index_bestcase][k_i].second> vec[i][m_i].first*1.0/vec[i][m_i].second)
					{
						index_bestcase = index_bestcase;
						break;

					}
					else if(vec[index_bestcase][k_i].first*1.0/vec[index_bestcase][k_i].second <  vec[i][m_i].first*1.0/vec[i][m_i].second)
					{
						index_bestcase = i;
						break;
					}
					
				}
			}
		}

		if ( best_case==make_pair(0,1))
		{
			return init_sum;
		}
		else if (best_case.second>M)
		{
			cout<<"Wrong";
		}
		else
		{
			// cout<<M<<" "<<(double)best_case.first*1.0/best_case.second<<" "<<best_case.first<<" "<<best_case.second<<" "<<index_bestcase<<endl;
			init_sum+=best_case.first;

			M = M - best_case.second;
			vec[index_bestcase].pop_front();
		}
	}
	return init_sum;

}
int main ()
{
	int T;
	cin>>T;
	for(size_t i =0;i<T;i++)
	{
		int N,M;
		cin>>M>>N;
		// cout<<N;
		std::vector<deque<pair<int,int>>> vec;
		vector<int> l_i;
		int init_sum = 0;
		for(size_t j =0 ; j<N;j++)
		{
			deque<pair<int,int>> this_deque;
			int L,K;
			cin>>K>>L;
			l_i.push_back(L);
			int last_Val;
			cin>>last_Val;
			int temp;
			if(L==1)
			{
				init_sum += last_Val;
			}
			for(size_t k =1;k<K;k++)
			{
				cin>>temp;
				this_deque.push_back(make_pair(temp-last_Val,0));
				last_Val = temp;
				if(k+1==L)
				{
					init_sum+=temp;
				}
			}
			for(size_t k =0;k<K-1;k++)
			{
				cin>>temp;
				this_deque[k].second = temp;
				// last_Val = temp;
			}
			// cout<<this_deque.size();
			vec.push_back(this_deque);
		}

		for(size_t ind_i =0 ; ind_i <l_i.size();ind_i++ )
		{
			while(l_i[ind_i]!=1)
			{
				vec[ind_i].pop_front();
				l_i[ind_i]--;
				// cout<<"y";
			}
		}
		// for(size_t j =0 ; j<N;j++)
		// {
		// 	for(size_t k =0 ; k<vec[j].size();k++)
		// 	{
		// 		cout<<j<<" "<<k<<" "<<vec[j].size()<<" "<<vec[j][k].first<<" "<<vec[j][k].second<<endl;
		// 	}
		// }
		cout<<"Case #"<<i+1<<": ";
		cout<<init_sum+find_sum(vec,l_i,M)<<endl;
		// cout<<vec.size();
		// for(size_t j =0 ; j<N;j++)
		// {
		// 	cout<<vec[j][1].first<<" "<<vec[j][1].second<<endl;
		// }
	}
}