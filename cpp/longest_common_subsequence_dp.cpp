/*input
sfdsdfdsfsdgfdsfgfdgsdf
dfgsdfgfdsgsdfgsdfg
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;
#define UP 0
#define LEFT 2
#define LEFTUP 1

string str_LCS(vector <vector <int >> &vec, string &str1,int n , int m)
{	string str;
	// cout<<n<<m<<endl;
	if (n==-1 ||m==-1)
		return str;
	else if (vec[n][m] ==LEFTUP)
		{	str =str_LCS(vec,str1,n-1,m-1)+ str1[n-1];
			// cout<<str1[n];
			return str;
		}
	else if (vec[n][m]==LEFT)
		return str_LCS(vec,str1,n,m-1);
	else
		return str_LCS(vec,str1,n-1,m);

}
int LCS(string &s1,string &s2, int i, int j )
{	
	// cout<<i<<j<<endl;
	// if(i==0&&j==0)
	// 	cout<<"ghjg";
	// if((i==0 && j==0)&&s1[i]==s2[j])
	// 	return 1;
	std::vector< std::vector<int> > v(s1.size()+1,std::vector<int>(s2.size()+1,0));
	std::vector< std::vector<int> > parent(s1.size()+1,std::vector<int>(s2.size()+1,0));
	for(size_t i=1;i<=s1.size();i++)
	{
		for(size_t j=1;j<=s2.size();j++)
		{
			if(s1[i-1]==s2[j-1])
				{	parent[i][j]= LEFTUP;
					v[i][j]=v[i-1][j-1]+1;
				}
			else
			{	if (v[i][j-1]>v[i-1][j])
				{
					v[i][j] = v[i][j-1];
					parent[i][j]=LEFT;
				}
				else
				{
					v[i][j] = v[i-1][j];
					parent[i][j]=UP;
				}
			}
		}
	}
	// for(size_t i=0;i<=s1.size();i++)
	// {
	// 	for(size_t j=0;j<=s2.size();j++)
	// 		cout<<v[i][j];
	// 	cout<<endl;
	// }
	// cout<<endl;
	// for(size_t i=0;i<=s1.size();i++)
	// {
	// 	for(size_t j=0;j<=s2.size();j++)
	// 		cout<<parent[i][j];
	// 	cout<<endl;
	// }

	string st = str_LCS(parent,s1,s1.size(),s2.size());
	if (st.empty()==true)
		cout<<"empty";
	cout<<st<<endl;
	return v[s1.size()][s2.size()];
	
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	// cout<<s1+s2[0];
	cout<<LCS(s1,s2,s1.size()-1,s2.size()-1);

}