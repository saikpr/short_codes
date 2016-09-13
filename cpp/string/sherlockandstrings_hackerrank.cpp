/*input
jtqgugmcsxvdwidtcyqpogkdifapuloqykjfxruvfrshcehekoiwbpbrprahwvhliglyxynjotbaswnnnmxbkmcftvsdqajemeul
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;
const int INT_MAX = ~(0u)>>1;
int main()
{
	std::vector<int> vec(26,0);
	string str;
	cin>>str;
	for(size_t i=0; i<str.size();i++)
	{
		vec[str[i]-'a']++;
	}
	int test_val_min=INT_MAX;
	int sum_f= 0, count_terms=0;
	for(size_t i=0; i<vec.size();i++)
	{
		// cout<<vec[i]<<" ";
		if(vec[i]==0)
			continue;
		count_terms++;
		sum_f += vec[i];
		// test_val_max = max(test_val_max,vec[i]);
		if(vec[i]!=1)
		test_val_min = min(test_val_min,vec[i]);
	}
	if (test_val_min==INT_MAX)
		cout<<"YES";
	else if(test_val_min*count_terms==sum_f||
		(test_val_min*count_terms+1)==sum_f||
		(test_val_min*(count_terms-1)+1)==sum_f)
		cout<<"YES";
	else
		cout<<"NO";
	
}