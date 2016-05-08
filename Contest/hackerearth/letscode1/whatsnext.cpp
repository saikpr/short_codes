#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>
using namespace std;

string next_largest(string str)
{
	size_t len= str.size();
	//cout<<"length :"<<len<<endl;
	unsigned int temp;
	char temp_char;
	bool done=false;
	temp=numeric_limits<int>::max();
	int i;
	bool check=false;
	for (i=0;i<len;i++)
	{
		if (temp >=(int)str[i])
			{
				temp=(int)str[i];
			}
		else
			{check=true;
				break;}

	}
	if ( check == false)
		{
			done =true;
			return string("no answer");
		}
	int j=0;
	for (i=0;i<len;i++)
	{
		if (str[i]<str[i+1])
		{
			j=i;
		}
	}
	cout<<j<<endl;
	char min=numeric_limits<char>::max();
	size_t index;
	for (i=j+1;i<len;i++)
	{	//cout<<min<<" "<<str[i]<<" "<<str[j]<<" "<<i<<" "<<j<<endl;
		if (min>=str[i] && str[i]>str[j])
		{
			min=str[i];
			index=i;
			// cout<<min<<" "<<index<<endl;

		}
	}
	// cout<<min<<" "<<index;
	swap(str[j],str[index]);
	reverse(str.begin()+j+1,str.end());

	return str;


}

int main()
{	long long int n;
	cin>>n;
	while(n-->0)
	{	string str;
		cin>>str;
		cout<<next_largest(str)<<endl;
    }
}
// int main()
// {
// 	string init_str("123");
// 	cin>>init_str;
// 	string k=init_str;
// 	cout<<k<<endl;
// 	while ((k=next_largest(init_str))!=string("no answer"))
// 	{	init_str=k;
// 		cout<<k<<endl;
// 	}
// }