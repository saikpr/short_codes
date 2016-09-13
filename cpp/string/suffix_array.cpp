/*input
abcabc
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
int comp_len(char *ch1, char* ch2)
{
	int i = 0;
	// int eq_len = 0;
	while((ch1[i]!='\0'||ch2[i]!='\0')&&ch1[i]==ch2[i])
		{i++;}
	return i;
}
vector < char *> create_suffix_array(char *str_chr, size_t len)
{
	// cout<<len<<endl;
	vector < char *> suffix_array;
	for(size_t i =0 ; i<len;i++)
	{
		suffix_array.push_back(str_chr+i);
	}
	sort(suffix_array.begin(),suffix_array.end(),comp);
	return suffix_array;
}
int main()
{
	vector < char *> suffix_array;
	string str;
	cin>>str;
	char str_arr[str.size()+1] ;
	strcpy(str_arr,str.c_str());
	suffix_array = create_suffix_array(str_arr,str.size());
	for(size_t i =0 ; i<suffix_array.size()-1;i++)
	{
		cout<<(suffix_array[i])<<" "<<suffix_array[i+1]<<endl;
		cout<<comp_len(suffix_array[i],suffix_array[i+1])<<endl;
		// printf("%ld\n",suffix_array[i] );
	}
	return 0;
}