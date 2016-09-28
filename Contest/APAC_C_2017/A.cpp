/*input
3
1 1 0 0 5
0.8000 0.2000
.
1 2 0 0 0
0.8000 0.2000
A A
1 6 0 0 5
0.8000 0.2000
. . . . . .
*/
#include <map>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<double> > visit;
bool is_first = true;
void backtrack(vector<vector<double> > vec,int Rs,int Cs, int S,double this_val,double &max_val)
{

	max_val =max(max_val,this_val);
	if(S==0)
	{
		// cout<<Rs<<":"<<Cs<<":"<<this_val<<endl;
		max_val =max(max_val,this_val);
		// if(this_val == 1.6)
		//  for(size_t i = 0 ; i < visit.size();i++)
		// {
		// 	// cin>>temp_str;
		// 	for(size_t j =0 ; j < visit[0].size(); j++)
		// 	{
		// 		cout<<visit[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		return;
	}
	else
	{
		// cout<<"Hehre";
		vector<pair<int,int> > possible;
		if (Rs-1>=0)
		{
			possible.push_back(make_pair(Rs-1,Cs));
		}
		if (Cs-1>=0)
		{
			possible.push_back(make_pair(Rs,Cs-1));
		}
		if (Rs+1<vec.size())
		{
			possible.push_back(make_pair(Rs+1,Cs));
		}
		if (Cs+1<vec[0].size())
		{
			possible.push_back(make_pair(Rs,Cs+1));
		}
		double old = vec[Rs][Cs];
		visit[Rs][Cs]++;
		if (is_first==false)
		{
			this_val= this_val + vec[Rs][Cs];
			if (visit[Rs][Cs]==1)

				vec[Rs][Cs] = vec[Rs][Cs] *pow((1-vec[Rs][Cs]),visit[Rs][Cs]);

		}
		else
		{
			is_first = false;
			this_val = 0;
		}

		// vec[Rs][Cs] = vec[Rs][Cs] *(1-vec[Rs][Cs]);
		
		
		for(size_t i = 0 ; i < possible.size();i++)
		{
			backtrack(vec,possible[i].first,possible[i].second,S-1,this_val,max_val);
		}


		vec[Rs][Cs] = old;
		visit[Rs][Cs]--;
	}
}

int main()
{
	int T;
	cin>>T;

	for(size_t t = 0 ; t < T;t++)
	{
		int R,C,Rs,Cs,S;
		cin>>R>>C>>Rs>>Cs>>S;
		double P,Q;
		cin>>P>>Q;
		// cin>>Q;
		// cout<<P<<" "<<Q<<endl;
		// cout<<Q<<endl;
		char temp;
		vector<vector<double> > vec(R,vector<double>(C,0));
		visit = vec;


		is_first=true;
		string temp_str;
		// cout<<R<<C<<Cs<<Rs<<P<<Q<<S<<endl;
		getline(cin,temp_str);
		for(size_t i = 0 ; i < R;i++)
		{
			getline(cin,temp_str);
			// cout<<temp_str<<endl;
			for(size_t j =0 ; j < C; j++)
			{
				// cin>>temp;
				// cout<<temp_str[2*j]<<" ";
				switch(temp_str[2*j])
				{
					case '.':vec[i][j] = Q;
							break;
					case 'A':vec[i][j] = P;
							break;
					default:cout<<"Shouldnt happen"<<endl;
				}
			}
		}

		double max_val=0;
		if(S!=0)
			backtrack(vec,Rs,Cs,S+1,(double)0.0000,max_val);
		cout<<"Case #"<<t+1<<": " <<max_val<<endl;
		// for(size_t i = 0 ; i < R;i++)
		// {
		// 	// cin>>temp_str;
		// 	for(size_t j =0 ; j < C; j++)
		// 	{
		// 		cout<<vec[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
	}
}