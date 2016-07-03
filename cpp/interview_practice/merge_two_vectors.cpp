/*input
2
hey
sam
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
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

template<class T>
void print_Vector(T &vec)
{
	for(size_t i =0;i<vec.size();i++)
	{
		cout<<vec.at(i);
	}
}
template<class T>
void merge_two_vectors(T &vec1, T &vec2, T &candidate, int n, int m)
{

	if(candidate.size()==(vec1.size()+vec2.size()))
	{
		print_Vector<T>(candidate);
		cout<<endl;
	}
	else
	{
		if(n<vec1.size())
		{
			candidate.push_back(vec1[n]);
			merge_two_vectors(vec1,vec2,candidate,n+1,m);
			candidate.pop_back();
		}
		if(m<vec2.size())
		{
			candidate.push_back(vec2[m]);
			merge_two_vectors(vec1,vec2,candidate,n,m+1);
			candidate.pop_back();
		}
	}
}

int main()
{
	int n;
	cin>>n;
	string vec1,vec2,candidate;
	// for(size_t i =0 ;i < n; i++)
	// {
	// 	cin>>vec1[i];
	// }
	// for(size_t i =0 ;i < n; i++)
	// {
	// 	cin>>vec2[i];
	// }
	cin>>vec1>>vec2;
	merge_two_vectors<string>(vec1,vec2,candidate,0,0);
	// interger_partition_backtrack(n,	 candidate,bracket_candidates);
}