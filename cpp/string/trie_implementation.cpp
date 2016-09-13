/*input
7
abdcd
sfd
g
dfg
dfh
fdfsd
fds
abdcd
*/

#include <iostream>
#include <stack>
#include <array>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#define MAXN 4
using namespace std;

struct trieNode 
{
	char elem;
	trieNode *next[255];

	trieNode (char theelem)
	{
		elem = theelem;
		for(size_t i =0 ; i<255; i++)
		{
			next[i] = NULL;
		}
	}
	trieNode ()
	{
		elem = '\0';
		for(size_t i =0 ; i<255; i++)
		{
			next[i] = NULL;
		}
	}

};


class trie
{
	trieNode *root;
public:
	trie()
	{
		root = new trieNode('\0');
	}
	bool is_prefix(string &thestr);
	void add_string(string &thestr);
	void print_trie();

};
bool all_null(const trieNode* vec)
{
	for(size_t i =0;i<255;i++ )
	{
		if(vec->next[i]!=NULL)
			return false;
	}
	return true;
}
void trie::print_trie()
{
	std::vector<pair<trieNode*,int>> vec;
	pair<trieNode*,int> temp_elem;
	vec.push_back(make_pair(root,-1));
	while(vec.size()!=0)
	{
		temp_elem = vec.at(vec.size()-1);
		vec.pop_back();
		// if(temp_elem.second == 255)
			
		int i = temp_elem.second+1;
		while(i<255 && temp_elem.first->next[i]==NULL)
		{
			i++;
		}
		// cout<<temp_elem.first->elem<<" "<<i<<endl;
		if(i!=255)
			{
				vec.push_back(make_pair(temp_elem.first,i));
				vec.push_back(make_pair(temp_elem.first->next[i],-1));
			}
		if(i==255 && all_null(temp_elem.first)==true)
		{
			for(size_t i =1 ;i <vec.size();i++)
			{
				cout<<vec[i].first->elem<<" ,";
			}
			cout<<temp_elem.first->elem<<endl;
		}


	}
}
void trie::add_string(string &thestr)
{
	int n = thestr.size();
	trieNode *temp = root, *new_temp;
	int index =0;
	if(n == 0)
	{
		return;
	}
	while(index<n)
	{
		if(temp->next[thestr[index]] == NULL)
		{
			new_temp = new trieNode(thestr[index]);
			// new_temp.elem = thestr[index];
			temp->next[thestr[index]] = new_temp;
		}
		temp = temp->next[thestr[index]] ;
		index++;
	}
}

bool trie::is_prefix(string &thestr)
{
	trieNode * temp = root;

	for(size_t i = 0; i < thestr.size();i++)
	{
		if(temp->next[thestr[i]]==NULL)
			return false;
		else

		{
			temp = temp->next[thestr[i]];
		}
	}
	return true;
}
int main()
{
	int N;
	cin>>N;
	trie theTrie;
	string temp_str;
	while(N-->0)
	{
		cin>>temp_str;
		theTrie.add_string(temp_str);
	}
	// theTrie.print_trie();
	cin>>temp_str;
	cout<<theTrie.is_prefix(temp_str);
}