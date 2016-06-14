/*input
abcdbaddad
abd
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool vector_compare(vector<int> &v1, vector<int> &v2)
{	
	bool flag = true;
	if (v1.size()!= v2.size())
		return false;
	for (int i=0; i<v1.size();i++)

	{	//cout<<v1[i]<<v2[i];
		if (v1[i]!=v2[i])
		{	//cout<<v1[i]<<v2[i];
			flag= false;
			break;
		}
	}
	return flag;
}

int substring_anagram(string &s1, string &s2)
{
	int n = s1.size(), m = s2. size();

	if (n<m)
	{
		return -1;
	}
	bool  flag = false;

	vector<int> v1(255),v2(255);
	fill(v1.begin(),v1.end(),0);
	fill(v2.begin(),v2.end(),0);

	for (int i=0; i <m;i++)
	{
		v1[s1[i]]++;
		v2[s2[i]]++;
	}
	int index = m;
	while ( index<n)
	{	
		// cout<<index;

		if (vector_compare(v1,v2)==true)
		{
			cout<<index-m<<endl;
		}
		v1[s1[index]]++;
		v1[s1[index-m]]--;
		index++;
	}

	
	return 0;
}

int main()

{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	substring_anagram(s1,s2);
}