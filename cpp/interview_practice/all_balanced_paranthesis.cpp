/*input
7
*/
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <unordered_map>
#include <utility>
using namespace std;

vector<string>  generate_all_paranthesis(int n)
{
	vector<vector<string> > possible_paranthesis(n+1);
	possible_paranthesis[0].push_back(string(""));
	possible_paranthesis[1].push_back(string("()"));
	if(n<=1)
		return possible_paranthesis[n];
	// cout<<"Here"<<endl;
	for(size_t i =2 ; i <=n;i++)
	{
		for(size_t j =0; j <i;j++)
		{
			int rem = i-j-1;
			vector<string> first_instance = possible_paranthesis[j],second_instance = possible_paranthesis[rem];

			for(size_t a =0 ; a<first_instance.size();a++)
			{
				for(size_t b = 0 ; b<second_instance.size();b++)
				{
					string temp="("+first_instance[a]+")"+second_instance[b];
					possible_paranthesis[i].push_back(temp);

				}
			}

		}
	}
	return possible_paranthesis[n];
}

int main()
{
	int n;
	cin>>n;
	vector<string> tmp = generate_all_paranthesis(n);
	cout<<tmp.size()<<endl;
	// for(size_t i = 0; i <tmp.size();i++)
	// {
	// 	cout<<tmp[i]<<endl;
	// }
}