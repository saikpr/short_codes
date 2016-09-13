/*input
2
ababaa  
aa
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

bool comp(char * ch1, char *ch2)
{
	return strcmp(ch1, ch2) < 0? 1 : 0;
}
int comp_len(char *ch1, char* ch2, int n_va)
{
	int i = (n_va>0?n_va:0);
	// int eq_len = 0;
	// cout<<ch1<<" "<<ch2<<endl;
	while((ch1[i]!='\0'&&ch2[i]!='\0')&&ch1[i]==ch2[i])
		{i++;}
	return i;
}
vector < char *> create_suffix_array(char *str_chr, size_t len)
{
	// cout<<len<<endl;
	vector < char *> suffix_array;
	for(size_t i =0 ; i<len;i++)
	{
		// cout<<i<<endl;
		// cout<<str_chr[0]<<str_chr[i]<<i<<endl;
		if(str_chr[i]==str_chr[0])
			suffix_array.push_back(str_chr+i);

	}
	// cout<<"Te"<<endl;
	sort(suffix_array.begin(),suffix_array.end(),comp);
	return suffix_array;
}
int main()
{
	int T;
	cin>>T;
	while(T-->0)
	{
		string str;
		cin>>str;
		char str_char[str.size()+1];
		strcpy(str_char,str.c_str());
		// cout<<T<<endl;
		// std::vector<char *> suffix_array = create_suffix_array(str_char,str.size());
		int count_a=0;
		for(size_t i =0; i < str.size();i++)
		{
			if(str_char[i]==str_char[0])
				count_a++;
			else
				break;
		}
		long long int sum_val = 0,temp_val;
		for(size_t i =0; i < str.size();i++)
		{
			temp_val= comp_len(str_char,str_char+i,count_a-i-1);
			sum_val +=temp_val;
		}
		// for(size_t i =0; i < suffix_array.size();i++)
		// {
			
		// 	temp_val= comp_len(str_char,suffix_array[i]);
		// 	sum_val +=temp_val;
		// }
		cout<<sum_val<<endl;
	}
}