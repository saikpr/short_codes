/*input
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
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

bool check_heights(vector <vector<int> > &vec)
{
	int n = vec.size();
	int temp_val = vec[0][vec[0].size()-1];
	for(size_t i=1;i<n;i++)
	{
		if (vec[i][vec[i].size()-1]!=temp_val)
			return false;
	}
	return true;

}

int equal_stack (vector <vector<int> > &vec)
{	
	int max_height=0, stack_count=-1;
	int n = vec.size();
	while(!check_heights(vec))
	{	max_height=0; stack_count=-1;
		for(size_t i=0;i<n;i++)
		{	
			if(vec[i].size()==0)
			return 0;
			if (vec[i][vec[i].size()-1]>max_height)
				{
					max_height = vec[i][vec[i].size()-1];
					stack_count = i;
				}
		}
		// cout<<"resizeing "<<stack_count<<" to "<<vec[stack_count].size()-1<<endl;
		vec[stack_count].resize(vec[stack_count].size()-1);
	}
	return vec[0][vec[0].size()-1];

}
int main() {
	
	vector<int> stack_height(3,0);
	for(size_t i=0;i<3;i++)
		cin>>stack_height[i];
	vector <vector<int> > vec(3);
	for(size_t i=0;i<3;i++)
		vec[i].resize(stack_height[i]);
	vector<int> temp;
	int t,index;
	for(size_t i=0;i<3;i++)
	{	
		temp.resize(stack_height[i]);

		for(size_t j=0;j<stack_height[i];j++)
		{
			cin>>t;
			temp[j]=t;
		}
		index=1;
		vec[i][0]=temp[stack_height[i]-1];
		for(size_t j=stack_height[i]-1;j>0;j--)
		{

			vec[i][index]= vec[i][index-1]+temp[j-1];
			index++;

		}
	}

	// for(size_t i=0;i<3;i++)
	// 	{
	// 		for(size_t j=0;j<stack_height[i];j++)
	// 		cout<<vec[i][j];
	// 		cout<<endl;
	// 	}
	cout<<equal_stack(vec);
    return 0;
}
