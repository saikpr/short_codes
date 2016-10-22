/*input
10
4 5 2 7 1 3 10 5 2 9 86 2
*/
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 100
using namespace std;


float median_of_vector(std::vector<int> &vec)
{
	int n=vec.size();
	priority_queue<int> min_heap,max_heap;

	for(size_t i = 0; i < n ;i++)
	{
		float possible_median = -1;
		if (min_heap.size()==0)
			{
				min_heap.push(vec[i]);
				continue;

			}
		if (min_heap.size()==max_heap.size())
		{
			possible_median = (-1.0*max_heap.top()+min_heap.top())/2;

		}
		else
		{
			possible_median = 1.0*min_heap.top();

		}
		if(possible_median>vec[i])
		{
			min_heap.push(vec[i]);
		}
		else
		{
			max_heap.push(-1*vec[i]);
		}
		// cout<<possible_median<<" "<<max_heap.top()<<" "<<min_heap.top()<<" "<<max_heap.size()<<" "<<min_heap.size()<<endl;

		if(max_heap.size()>min_heap.size())
		{
			// cout<<"here1"<<endl;
			while(max_heap.size()>min_heap.size())
			{
				int k = -1*max_heap.top();
				max_heap.pop();
				min_heap.push(k);
			}
		}
		else if(max_heap.size()+1<min_heap.size())
		{
			// cout<<"here2"<<endl;
			while(min_heap.size() > max_heap.size())
			{
				int k = -1*min_heap.top();
				min_heap.pop();
				max_heap.push(k);
			}

		// cout<<possible_median<<endl;
		// cout<<max_heap.size()<<" "<<min_heap.size()<<endl;
	}
	}
	if (min_heap.size()==max_heap.size())
	{
		return (-1.0*max_heap.top()+min_heap.top())/2;

	}
	else
	{
		return 1.0*min_heap.top();

	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	std::vector<int > vec(n);
	for(size_t i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	cout<<median_of_vector(vec);
}