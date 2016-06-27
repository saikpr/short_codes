/*input
setve
estve
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
#include <string>

#define MATCH 0
#define DELETE1 1
#define DELETE2 2
#define SWAP 3
using namespace std;

int edit_distance(string &s1, string s2)
{
	int n = s1.size(), m= s2.size();
	vector<int> opt(4);

	vector <vector <int> > edit_matrix(n+1,vector<int> (m+1));

	for(size_t i =1 ; i<=n;i++)
	{
		edit_matrix[i][0]=i;
	}
	for(size_t j =1 ; j<=m;j++)
	{
		edit_matrix[0][j]=j;
	}

	for(size_t i =1 ; i<=n;i++)
	{
		for(size_t j =1 ;j<=m;j++)
		{
			opt[MATCH] = edit_matrix[i-1][j-1] + ((s1[i-1]==s2[j-1])?0:1);
			opt[DELETE1]=edit_matrix[i-1][j]+1;
			opt[DELETE2]=edit_matrix[i][j-1]+1;
			if (i>1 &&j>1&&s1[i-1]==s2[j-2] &&s1[i-2]==s2[j-1] &&s1[i-2]!=s1[i-1])
			{
				opt[SWAP] = edit_matrix[i-2][j-2] + 1;
				// cout<<i<<j;
			}
			else 
			opt[SWAP] = n+1;
			edit_matrix[i][j]=min(opt[0],min(opt[1],min(opt[3],opt[2])));

			// for(size_t i_1 =0 ; i_1<=n;i_1++)
			// 	{
			// 		for(size_t j_1 =0 ;j_1<=m;j_1++)
			// 		{
			// 			cout<<edit_matrix[i_1][j_1];
						

			//  		}
			//  		cout<<endl;
			// 	}

			// cout<<i<<j<<opt[0]<<opt[1]<<opt[2]<<min(opt[0],min(opt[1],opt[2]))<<endl<<endl;


 		}
	}
	// cout<<endl;
	// for(size_t i =0 ; i<=n;i++)
	// {
	// 	for(size_t j =0 ;j<=m;j++)
	// 	{
	// 		cout<<edit_matrix[i][j];
			

 // 		}
 // 		cout<<endl;
	// }
	return edit_matrix[n][m];



}


int main()
{
	string s1,s2;
	getline(cin,s1,'\n');
	// cout<<s1;
	getline(cin,s2,'\n');
	// cout<<s2;
	cout<<edit_distance(s1,s2);

}