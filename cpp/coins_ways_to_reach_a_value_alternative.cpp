/*input
4
2 3 5 6
10
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

void print_vec ( std::vector<std::vector<int> > &vec)
{
	int n=vec.size();
	
	int m=vec[0].size();
	// cout<<n<<endl;
	for(size_t i =0; i<n;i++)
	{	cout<<i<< " ";
		for (size_t j =0 ;j <m;j++)
		{
			cout<<vec[i][j]<<" " ;
		}
		cout<<endl;
	}
}

int  coins_count (std::vector<int> &coin_deno, int value)
{
	int n = coin_deno.size();
	std::vector< int > vev(value+1,0);
	vev[0]=0;
	for (size_t i = 0;i<n;i++)
	{
		
	}

}



int main ()
{
	int N;
	cin>>N;
	std::vector< int > v;
	// v.resize(N);
	int temp;
	while(N-->0)
	{
		cin>>temp;
		v.push_back(temp);
	}
	int value;
	cin>>value;
	// cout<<"here"<<endl;
	coins_count(v,value);
}