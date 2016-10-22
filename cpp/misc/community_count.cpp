/*input
3 6
Q 1
M 1 2
Q 2
M 2 3
Q 3
Q 2
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_group(vector<int> &communities, int val)
{
	while(val!=communities[val])
	{
		val = communities[val];
	}
	return val;
}

void merge_groups(vector<int> &communities, vector<int> &size_comm, int A, int B)
{
	int root_A = find_group(communities,A), root_B = find_group(communities,B);

	if (root_A==root_B)
		return;

	if (size_comm[root_A]>size_comm[root_B])
	{
		communities[root_B] = root_A;
		size_comm[root_A] += size_comm[root_B];
	}
	else
	{
		communities[root_A] = root_B;
		size_comm[root_B] += size_comm[root_A];
	}
	return;
}
int main() {
    int N,Q;
    cin>>N>>Q;

    vector<int> communities(N+1);
    vector<int> size_comm(N+1,1);
    for(size_t i =0 ; i < communities.size();i++)
    {
    	communities[i] = i ;
    }
    char ch;
    int g1,g2;
    for(size_t q =0 ; q<Q;q++)
    {
    	cin>>ch;

    	switch(ch)
    	{
    		case 'Q':

    				cin>>g1;
    				cout<<size_comm[find_group(communities,g1)]<<endl;
    				break; 	
    		case 'M':
    				cin>>g1>>g2;

    				merge_groups(communities,size_comm,g1,g2);
    				break;

    		default: cout<<"Invalid Input"<<endl;
    	}
    }
    return 0;
}
