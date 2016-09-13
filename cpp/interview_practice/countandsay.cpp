/*input
7
4 7 7 7 8 10 10 
3
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
int COUBT_VAL =0 ;

bool check_valid(std::vector<int> &vec)
{
	if (vec.size()!=4)
		return false;
	for(size_t i =0 ; i < 4 ;i++)
	{
		if (vec[i]<0 || vec[i]>255)
			return false;
	}
	return true;
}

void ip_addr(string &A, vector<string> &solutions, vector<int> &this_soln,int k)
{
	COUBT_VAL++;
	if (this_soln.size()>4)
		return;

	if (k == A.size())
	{
		
		if (check_valid(this_soln))
		{
			stringstream  ss;
			ss<<this_soln[0]<<"."<<this_soln[1]<<"."<<this_soln[2]<<"."<<this_soln[3];
			solutions.push_back(ss.str());
		}
		
	}
	else
		{
			vector < pair<int,int> > possible_candidates;
			int tem_val=0;
			if(A[k]!='0')
			{
				for (size_t i=k;i<A.size();i++)
				{
					tem_val *=10;
					tem_val+=(A[i]-'0');
					if (tem_val <256)
						possible_candidates.push_back(make_pair(tem_val,i-k+1));
					else
						break;

				}
			}else
			{
				possible_candidates.push_back(make_pair(0,1));
			}
			for(size_t i =0 ; i <possible_candidates.size();i++)
			{
				this_soln.push_back(possible_candidates[i].first);
				ip_addr(A,solutions,this_soln,k+possible_candidates[i].second);
				this_soln.pop_back();
			}
		}
}


vector<string> restoreIpAddresses(string A) {
vector<int> this_soln;
std::vector<string> solutions;
ip_addr(A,solutions,this_soln,0);
sort(solutions.begin(), solutions.end());
return solutions;
}




int main()
{
	vector<string> k = restoreIpAddresses(string("25525511135"));
	for (size_t i = 0; i <k.size();i++)
		cout<<k[i]<<endl;
	cout<<COUBT_VAL;
	// int n;
	// cin>>n;
	// vector<int> vec(n);
	// for (size_t i = 0; i < n;i++)
	// {
	// 	cin>>vec[i];
	// }
	// int B;
	// cin>>B;
	// vector<int> tmp = searchRange(vec,B);
	// cout<<tmp[0]<<" "<<tmp[1]<<endl;
	// for (size_t i = 0; i < n;i++)
	// {
	// 	cout<<vec[i]<<" "<<sqrt(vec[i])<<endl;
	// }
	// cout<<sqrt(308634616)<<endl;

}
