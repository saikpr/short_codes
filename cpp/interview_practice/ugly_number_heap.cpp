#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;


std::vector<int> ugly_number(int n)
{
	vector<int> to_return(1,0);
	priority_queue<int ,std::vector<int>, std::greater<int>> p1;

	p1.push(1);

	int count =0;
	while(count<n)
	{
		count++;
		int temp = p1.top();
		p1.pop();
		// cout<<temp<<" "<<to_return[to_return.size()-1]<<endl;
		while(temp==to_return[to_return.size()-1])
		{
			temp = p1.top();
			p1.pop();
		}
		p1.push(temp*2);
		p1.push(temp*3);
		p1.push(temp*5);
		to_return.push_back(temp);
	}
	return to_return;
}


int main()
{
	int n=1000;

	vector<int> vec =ugly_number(n);
	// for(size_t i =0; i<vec.size();i++)
	// cout<<vec[i]<<" ";
	cout<<vec[vec.size()-1]<<endl;
}