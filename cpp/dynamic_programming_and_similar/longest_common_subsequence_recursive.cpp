/*input
AGGTAB
GXTXAYB
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int LCS(string &s1,string &s2, int i, int j )
{	
	// cout<<i<<j<<endl;
	// if(i==0&&j==0)
	// 	cout<<"ghjg";
	// if((i==0 && j==0)&&s1[i]==s2[j])
	// 	return 1;
	if ((i==-1 || j==-1))
		return 0;
	if(s1[i]!=s2[j])
		{
			// cout<<s1[i]<<" ";
			
			return max(LCS(s1,s2,i-1,j),LCS(s1,s2,i,j-1));
		}
	else
		{
			return 1+LCS(s1,s2,i-1,j-1);
			// cout<<"Checking "<<i-1<<j<<" "<<i<<j-1<<endl;
			}

}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	// cout<<s1+s2[0];
	cout<<LCS(s1,s2,s1.size()-1,s2.size()-1);

}