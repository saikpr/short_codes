#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch[10000];

	int a[26]={0};
	cin.getline(ch,10000);
	cout<<ch;
	int i=0;
	int count=0;

	while(ch[i]!='\0')
	{	if (ch[i]>='a' && ch[i]<='z')
			{a[ch[i]-97]++;count++;}
		i++;
	}
	cout<<endl;
	for( i=0;i<26;i++)
	{
		cout<<i<<" "<<a[i]<<endl;
	}
}