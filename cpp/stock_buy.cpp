/*input
4
1 2 3 4
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


int best_stock_price(std::vector<int> &vec)
{
	int N = vec.size();

	int min_elem = vec[0];
	int max_diff = 0;
	for(size_t i =1; i<N;i++)
	{
		if (min_elem >vec[i])
		{
			min_elem = vec[i];

		}

		max_diff = max(max_diff,vec[i]-min_elem);
	}
	return max_diff;

}
int main()
{
	int N;
	cin>>N;
	std::vector<int> stock_price(N);
	for (size_t i=0;i<N;i++)
	{
		cin>>stock_price[i];
	}
	cout<<best_stock_price(stock_price);
}