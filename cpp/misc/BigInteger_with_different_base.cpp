/*input
9
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;
#define MAX_VALUE 100

class BigInteger
{
protected:
	vector<unsigned int> data;
	bool isPositive;
	unsigned int base ;
public:
	BigInteger();
	BigInteger(string&);
	BigInteger(BigInteger&);
	BigInteger add(BigInteger&);
	BigInteger substract(BigInteger&);
	string operator<<(BigInteger&);
	string operator>>()
	void print(ostream&);
	void increment();
	void toString();

};
BigInteger::BigInteger()
{
	data.resize(1);
	data[0]=0;
}
BigInteger::BigInteger(string &vec)
{
	data.resize(vec.size());
	for(size_t i=0;i<vec.size();i++)
	{
		data[i] = vec[i]-'0';
	}
}
void BigInteger::print(ostream &out)
{
	for(size_t i =0;i<data.size();i++)
	{
		out<<data[i]<<" ";
	}
}
void BigInteger::increment()
{
	int index= data.size()-1;
	data[index]++;
	// cout<<data[index]<<endl;
	while(index>0 && data[index]>9)
	{
		// cout<<index<<" "<<data
		data[index-1]++;
		data[index]=0;
		index--;
	}
	if(index==0 && data[index]>9)
	{
		data.resize(data.size()+1);
		copy_backward(data.begin(),data.end()-1,data.end());
		data[0]=1;
		data[1]=0;
	}

}
int main()
{
	string dummy_str;
	cin>>dummy_str;
	BigInteger b1(dummy_str);
	b1.print(cout);
	b1.increment();
	cout<<endl;
	b1.print(cout);


}