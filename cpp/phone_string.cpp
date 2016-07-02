/*input
9944867152
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void phone_strings(string &number,std::vector<string> &candidates,string candidate =string())
{
	int n = number.size();
	int k = candidate.size();
	// cout<<n<<" "<<k<<endl;
	vector<string> ref_str={"+","-","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
	string possible_str;
	if (n==k)
	{
		candidates.push_back(candidate);
		return;
	}
	else
	{	
		possible_str = ref_str[(int)(number[k]-'0')];
		for(size_t i =0 ;i<possible_str.size();i++)
		{
			if(i!=0)
			{
				candidate.pop_back();
			}
			candidate.push_back(possible_str[i]);
			phone_strings(number,candidates,candidate);
		}
		return;
	}

}

int main()
{
	string number;
	cin>>number;
	std::vector<string> possible_candidates;
	phone_strings(number,possible_candidates);
	for(size_t i =0;i<possible_candidates.size();i++)
	{
		cout<<possible_candidates[i]<<endl;
	}
}