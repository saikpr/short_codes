/*input
64197
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#define MAXN 100
using namespace std;


struct Node {int data; Node * next;
	

	Node (int &thedata)
	{
		data = thedata;
		next =NULL;	
	}
	Node ()
	{
		data = 0;
		next=NULL;
	}
	~Node ()
	{
		cout<<"Deleting :"<<this->data<<endl;
		
	}
};

Node * convert_vector_to_linkedlist(vector<int> &vec)
{
	size_t size = vec.size();
	Node *temp=NULL,*head=NULL,*tail=NULL;
	if (size == 0)
	{
		return head;
	}

	for (size_t i =0; i<size;i++)
	{
		temp = new Node(vec[i]);
		if (i==0)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail =temp;
		}

	}
	return head;

}


int main()
{
	// cout<<"Hello World";
	string s1,s2;
	cin>>s1;
	// cin>>s2;

	vector<int> v1(s1.size());
	for (size_t i =0 ; i<s1.size();i++)
	{
		v1[i] = s1[i]-'0';
	}
	Node  *head_1 = convert_vector_to_linkedlist(v1);
	Node  *temp =head_1;

	while(temp !=NULL)
	{
		cout<<temp->data<<",";
		temp= temp->next;
	}

}

