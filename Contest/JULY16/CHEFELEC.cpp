/*input
3
2
01
1 2
3
010
1 5 6
7
1
1 5 6 9 11 13 14
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
// #include <unordered_map>
#include<limits>
using namespace std;
#define MAX_BITS 100000

long long min_leng(std::vector<long long> &village_pos, bitset<MAX_BITS> &bit_light)
{
	
	long long N = village_pos.size();
	// cout<<N<<endl;
	long long wire_len = 0;
	long long j=0,k;
	if (bit_light[0]==0)
	{
		while(j<N&&bit_light[++j]!=1)
		{}
	
		wire_len += (village_pos[j]-village_pos[0] );
		while(j>=0)
		{
			bit_light[j--]=1;
		}
	}
	j=N-1;
	if (bit_light[j]==0)
	{
		while(j>=0&&bit_light[--j]!=1)
		{}

		
		// cout<<bit_light[j]<<endl;
		wire_len += (village_pos[N-1]-village_pos[j] );
		while(j<N)
		{
			bit_light[j++]=1;
		}
	}
	// cout<<bit_light<<endl;
	bool flag = false;
	for(size_t i =1 ; i< N-1;)
	{	
		long long min_distance = std::numeric_limits<long long>::max();
		long long light_village =-1;
		if (bit_light[i]==0)
		{
			if (flag == false)
			{
				j = i+1;
				while(j<N&&bit_light[j]==0)
				{
					j++;
				}
			}
			else
			{
				j--;
				flag =false;
			}
			// j--;
			// if(j==N)

			if(min_distance>(village_pos[i]-village_pos[i-1]))
			{
				light_village = i;
				min_distance = (village_pos[i]-village_pos[i-1]);
			}
			if(min_distance>(village_pos[j]-village_pos[j-1]))
			{
				light_village = j-1;
				min_distance = (village_pos[j]-village_pos[j-1]);
			}
			// if (light_village>0 && light_village<N-1)
			bit_light [light_village] = 1;
			wire_len += min_distance;
			// cout<<"Lighting "<<light_village;
		}
		if(bit_light[i]==1)
		{
			i++;
		}
		else
		{
			flag = true;
		}
	}
	// cout<<bit_light<<endl;
	return wire_len;
}

int main()
{
	long long T;
	cin>>T;
	while(T-->0)
	{
		long long N;
		cin>>N;
		string str_bit;
		cin>>str_bit;
		bitset<MAX_BITS> bit_light(std::string(str_bit.rbegin(), str_bit.rend()));
		long long temp;
		vector <long long> village_pos(N);
		for(size_t i =0; i < N;i++)
		{
			cin>>village_pos[i];
			// village_pos.push_back(temp);
		}
		// cout<<bit_light[2]<<endl;
		cout<<min_leng(village_pos,bit_light);
		cout<<endl;
	}

}