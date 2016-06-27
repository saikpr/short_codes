/*input
4
oso
aa
cccce
x
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
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long count_find(string &s1, int mod)
{
	int n = s1.size();
	long long res=1;
	if (n==1)
		return 1;
	else if (s1[0]==s1[1])
	{
		res *=1;

	}
	else if (s1[0]!=s1[1])
	{
		res*=2;
	}


	if(s1[n-2]!=s1[n-1])
		res*=2;
	if (n==2)
		return res;
	// cout<<res<<n;
	int counter=0;
	for (size_t i =1 ; i<n-1;i++)
	{	counter =1 ;
		// cout<<s1[i-1]<<s1[i]<<s1[i+1]<<endl;
		if ((s1[i-1]==s1[i]) && (s1[i+1]==s1[i]))
			counter=1;

		else if((s1[i-1]==s1[i]&&s1[i]!=s1[i+1])||(s1[i+1]==s1[i]&&s1[i]!=s1[i-1])||(s1[i-1]==s1[i+1]&&s1[i]!=s1[i+1]))
			counter =2;
		else
			counter =3;
		// cout<<counter<<endl;
		res = ((res%mod) *(counter%mod))%mod ;

	}
	return res;
}


int main()
{
	int N;
	cin>>N;

	for (size_t index=0 ; index<N;index++)
	{	
		string str;
		cin>>str;
		cout<<"Case #"<<index+1<<": "<<count_find(str,1000000007 )<<endl;

	}
}