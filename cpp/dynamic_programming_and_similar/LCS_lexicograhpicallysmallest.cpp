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
#include <queue>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;


string LCS_lexo(string &A, string &B)
{
	int n = A.size(), m = B.size();
	vector< vector<unordered_set<string> > > strings(n+1,vector<unordered_set<string>>(m+1));

	vector<unordered_set<string> > opt(3);
	unordered_set<string> temp;
	int max_len=0;
	for(size_t i = 1  ; i <= n ; i++)
	{
		for(size_t j = 1 ; j <=m ; j++)
		{
			opt[0] = strings[i-1][j];
			opt[1] = strings[i][j-1];
			if (A[i-1]==B[j-1])
				opt[2] = unordered_set<string>((A[i-1]==B[j-1])?string(1,A[i-1]):string());
			else
				opt[2] = strings[i-1][j-1]
			
			temp = unordered_set<string>();
			max_len=0;
			for(size_t k=0;opt.size();k++)
			{
				if (opt[k].size()!=0)
				{
					max_len = max(max_len,(*(opt[k].begin())).size());
				}
			}
			for(size_t k=0;opt.size();k++)
			{
				if ((*(opt[k].begin())).size()==max_len)
				{
					for(auto it = opt[k].begin();it!=opt[k].end();it++)
					{
						temp.insert(*it);
					}
				}
			}
			strings[i][j] = temp;

		}
	}
	if (strings[n][m].size()==0)
	{
		return string(":(");
	}
	return strings[n][m];


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
		cout<<"Case "<<i+1<<": "<<LCS_lexo(A,B)<<endl;
	}
	return 0;
}