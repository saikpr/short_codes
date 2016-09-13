/*input
1234
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
bool test_func( T (*thefunction)(T&))
{	
	T elem;
	cin>>elem;
	T result;
	cin>>result;
	T generated_result;
	generated_result = (*thefunction)(elem);
	// cout<<elem;
	if (generated_result!=result)
		return false;
}

string next_largest(string &str)
{
	int n= str.size();
	string new_str;
	int max_i = -1, max_j = -1;
	for (size_t i = 0 ; i< n-1 ; i++)
	{
		if(str[i]<str[i+1])
			max_i = i;
	}
	// cout<<max_i;
	if (max_i ==-1)
		return new_str;
	for(size_t j = max_i; j<n;j++)
	{
		if (str[max_i]<str[j])
			max_j = j;
	}
	new_str = str; //copy(str.begin(),str.end(),new_str.begin())
	swap(new_str[max_i],new_str[max_j]);
	reverse(new_str.begin()+max_i+1,new_str.end());
	// cout<<max_i<<max_j<<endl;
	return new_str;
}

int main()
{	
	// bool k;
	// while(cout<<test_func<string>(next_largest))
	// {}
	string str;
	cin>>str;
	do{
	cout<<str<<endl;}
	while(!(str = next_largest(str)).empty());
}