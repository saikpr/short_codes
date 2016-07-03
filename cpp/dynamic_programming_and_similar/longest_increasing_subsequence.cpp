/*input
243517698
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>

#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

int longest_increasing_subsequence(string &s1)
{
	int n=s1.size();
	if (n ==0)
		return 0;
	if (n==1)
		return 1;
	vector <array<int,2> > vec(n);
	vec[0][0] = 1;
	vec[0][1] = -1;

	int max_val = -1;
	int max_index = -1;

	for (size_t i=1;i<n;i++)
	{	
		max_val = 0;
		max_index = -1;
		for(size_t j=0; j<i;j++)
		{
			// cout<<i<<j<<s1[j]<<s1[i]<<endl;
			if (s1[j]<s1[i])
			{

				if (max_val<vec[j][0])
				{
					max_val = vec[j][0];
					max_index = j;
				}
			}
		}
		if (max_index == -1)
		{
			vec[i][0] = 1 ;
			vec[i][1] = -1;
		}
		else
		{
			vec[i][0] = max_val+1;
			vec[i][1] = max_index;
		}
	}
	max_val =0;
	max_index = -1;
	for(size_t i=0;i<n;i++)
	{
		cout<<vec[i][0]<<vec[i][1]<<endl;
		if (max_val<vec[i][0])
				{
					max_val = vec[i][0];
					max_index = i;
				}
	}

	// while(max_index!=-1)
	// {
	// 	cout<<s1[max_index];
	// 	max_index = vec[max_index][1];
	// }
	// cout<<endl;
	return max_val;
}

int main()
{
	string s1;
	cin>>s1;
	// cout<<s1+s2[0];
	cout<<longest_increasing_subsequence(s1);

}