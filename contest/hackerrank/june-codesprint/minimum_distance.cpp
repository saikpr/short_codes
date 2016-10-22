/*input
6
7 1 3 4 1 7
*/
#include <map>
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

int minimum_distance(vector<int> &vec)
{
	array<int,100000> a1;
	fill(a1.begin(),a1.end(),-1);
	int n = vec.size();
	int min_val = n;
	for(size_t i =0 ; i< n;i++)
	{
		if(a1[vec[i]]==-1)
		{
			a1[vec[i]] = i;
		}
		else
		{
			min_val = min(min_val,(int)i-a1[vec[i]]);
			a1[vec[i]] = i;
		}
	}
	return ((min_val == n)?-1:min_val);
	// return min_val;
}


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0;i < n;i++){
       cin >> A[i];
    }
    cout<<minimum_distance(A);
    return 0;
}
