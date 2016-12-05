/*input
3
1 2
2 1 3
1 1
*/
#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;
const int SEARCH=1;
const int PUT=2;
typedef int key_ct;
typedef int val_ct;
struct doublyNode
{
	key_ct key;
	val_ct val;
	doublyNode *back,*ahead;
	doublyNode():key(-1),val(-1),back(NULL),ahead(NULL){}

};

class doublyList
{
	private:
		doublyNode *header;

	public:
		doublyList()
		{
			header = new doublyNode;
			header->ahead = header;
			header->back = header;
		}

		void insert_at_start(doublyNode *elem )
		{
			assert(elem!=NULL);

			doublyNode *temp;
			temp = header->ahead;
			header->ahead = elem;
			elem->ahead = temp;
			temp->back = elem;
			elem->back = header;
			return;
		}

		doublyNode * remove_node(doublyNode *elem=NULL)
		{
			if (elem==NULL)
			{
				elem = header->back;
			}
			assert(elem !=NULL);
			 // doublyNode *temp;
			 elem->back->ahead = elem->ahead;
			 elem->ahead->back = elem->back;
			 return elem;
		}

};
class myLRUCache
{
	private:
		doublyList *elements_list;
		unordered_map<key_ct,doublyNode*> key_to_node;
		int LRUcapacity ;
		int present_capacity ;
	public:
		myLRUCache(int capacity):present_capacity(0)
		{
			elements_list = new doublyList;
			LRUcapacity = capacity;
			// present_capacity=0;
		}

		void insert_key(key_ct theKey, val_ct theVal)
		{
			if (key_to_node.count(theKey)==1)
			{
				doublyNode *temp = key_to_node[theKey];
				temp ->val = theVal;
				elements_list->remove_node(temp);
				elements_list->insert_at_start(temp);
				return;
			}
			if(present_capacity == LRUcapacity)
			{
				doublyNode * temp = elements_list->remove_node();
				key_to_node.erase(temp->key);
				delete temp;
				present_capacity--;
			}
			doublyNode *temp = new doublyNode;
			temp->key = theKey;
			temp->val = theVal;
			//cout<<"Done"<<endl;
			elements_list->insert_at_start(temp);
			key_to_node[theKey] = temp;
			present_capacity++;

		}

		val_ct get_value(key_ct theKey)
		{
			if (key_to_node.count(theKey)==1)
			{
				doublyNode * temp  = key_to_node[theKey];
				elements_list->remove_node(temp);
				elements_list->insert_at_start(temp);
				return temp->val;
			}
			else
			{
				return -1;
			}
		}
};

int main()
{
	int N;
	cin>>N;
	// cout<<N;
	myLRUCache myCache(1);
	for(int n = 0 ;  n < N ; n++)
	{
		int queryType;
		cin>>queryType;
		// cout<<queryType;
		key_ct theKey;
		val_ct theVal;
		switch(queryType)
		{
			case SEARCH:
						cout<<"Searching"<<endl;
						cin>>theKey;
						cout<<myCache.get_value(theKey)<<endl;
						break;
			case PUT:
						cout<<"Putting"<<endl;
						cin>>theKey>>theVal;
						myCache.insert_key(theKey,theVal);
						break;
			default:
						assert(false);

		}
	}
}