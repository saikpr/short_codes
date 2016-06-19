/*input
abcdedsafghi abcdscsdfoewr
100
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
		cout<<"Deleting"<<this->element;
		~element();
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
Node<T>* return_kth_last(Node<T>* &head, int k)
{
	Node<T>* front=NULL, *back=NULL;
	back = head;
	while(k-->0 && back!=NULL)
	{
		back = back->next;
	} 
	if(back!=NULL)
	{
		front =head;
	}
	while(back!=NULL && back->next!=NULL)
	{
		front =front->next;
		back = back->next;
	}
	return front;
}
int main()
{
	// cout<<"Hello World";
	string s1;
	getline(cin,s1,'\r');
	int K;
	cin>>K;

	vector<char> v1(s1.begin(),s1.end());
	Node <char> * head = convert_vector_to_linkedlist<char>(v1);
	Node <char> *temp =return_kth_last(head,K);
	if (temp!=NULL)
		cout<<temp->element;


}