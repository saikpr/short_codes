/*input
abcdedsafghi abcdscsdfoewr
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#define MAXN 100
using namespace std;

template <class T>
struct Node {T element; Node<T> * next;
	

	Node (T &theelement)
	{
		element = theelement;
		next =NULL;	
	}
	~Node ()
	{
		cout<<"Deleting :"<<this->element<<endl;
		
	}
};

template<class T>
Node<T> * convert_vector_to_linkedlist(vector<T> &vec)
{
	size_t size = vec.size();
	Node<T> *temp=NULL,*head=NULL,*tail=NULL;
	if (size == 0)
	{
		return head;
	}

	for (size_t i =0; i<size;i++)
	{
		temp = new Node<T>(vec[i]);
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

template<class T>
bool remove_duplicate ( Node<T>* &head )
{
	Node<T>	*temp1, *temp2,*prev,*todelete;
	temp1 = temp2 = head;
	while(temp1!=NULL)
	{
		temp2 =temp1->next;
		prev = temp1;
		while(temp2!=NULL)
		{	
			// temp2 = temp2->next;
			if(temp2->element == temp1->element)
			{	
				// cout<<temp2->element;
				todelete = temp2;
				prev->next = temp2->next;
				// if(prev->next)
					temp2 = prev->next;
					delete todelete;
				
			}
			else
			{
				prev = prev->next;
				temp2 = prev->next;
			}
		}
		temp1= temp1->next;

	}
	return true;
}
int main()
{
	// cout<<"Hello World";
	string s1;
	getline(cin,s1,'\r');

	vector<char> v1(s1.begin(),s1.end());
	Node <char> * head = convert_vector_to_linkedlist<char>(v1);
	Node <char> *temp =NULL;
	remove_duplicate(head);
	temp =head;
	while(temp !=NULL)
	{
		cout<<temp->element<<",";
		temp= temp->next;
	}

}