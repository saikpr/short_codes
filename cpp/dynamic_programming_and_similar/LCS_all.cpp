/*input
3
ab
ba 
zxcvbn
hjgasbznxbzmx 
you
kjhs
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;


vector<string> LCS_lexo(string &A, string &B)
{
	int n = A.size(), m = B.size();
	vector< vector<set<string> > > strings(n+1,vector<set<string>>(m+1));

	vector<set<string> > opt(3);
	set<string> temp;
	int max_len=0;
	for(size_t i = 1  ; i <= n ; i++)
	{
		for(size_t j = 1 ; j <=m ; j++)
		{
			// cout<<i<<" "<<j<<endl;
			opt[0] = strings[i-1][j];
			opt[1] = strings[i][j-1];
			if (A[i-1]==B[j-1])
				{
					// cout<<"heher"<<endl;
					opt[2] = set<string>();
					if(strings[i-1][j-1].size()!=0)
					for(auto it = strings[i-1][j-1].begin();it!=strings[i-1][j-1].end();it++)
					{
						opt[2].insert((*it)+A[i-1]);
					}
					else
					{
						opt[2].insert(string(1,A[i-1]));
					}
				}
			else
				opt[2] = strings[i-1][j-1];
			
			temp = set<string>();
			max_len=0;
			// cout<<i<<"v "<<j<<" "<<opt.size()<<endl;
			for(size_t k=0; k<opt.size();k++)
			{
				// cout<<k<<" "<<opt[k].size()<<endl;
				if (opt[k].size()!=0)
				{
					string one_str = *(opt[k].begin());
					max_len = max(max_len,(int)one_str.size());
				}
			}
			if (max_len==0)
				continue;
			// cout<<i<<" "<<j<<max_len<<endl;
			for(size_t k=0;k!=opt.size();k++)
			{
				if(opt[k].size()==0)
					continue;
				string one_str = *(opt[k].begin());
				if ((int)one_str.size()==max_len)
				{
					for(auto it = opt[k].begin();it!=opt[k].end();it++)
					{
						temp.insert((*it));
					}
				}
			}
			strings[i][j] = temp;

		}
	}
	

	vector<string> to_return;
	for(auto it = strings[n][m].begin();it!=strings[n][m].end();it++ )
	{
		to_return.push_back(*it);
	}
	return to_return;


}


int main()
{
	int n ; 
	cin>>n;
	string A,B;
	for(size_t i =0 ; i <n;i++ )
	{
		cin>>A;
		cin>>B;
		vector<string> temp = LCS_lexo(A,B);
		for(size_t j = 0 ; j < temp.size();j++)
		{
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}