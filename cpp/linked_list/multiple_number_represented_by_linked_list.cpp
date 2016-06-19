/*input
9939
12335
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

template <class T>
struct Node {T element; Node<T> * next;
	

	Node (T &theelement)
	{
		element = theelement;
		next =NULL;	
	}
	Node ()
	{
		element = 0;
		next=NULL;
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


template <class T>
Node<T> * sum_linkedlist(Node<T> * &head1, Node<T> *  &head2)
{
	unsigned int buffer_val = 0;

	Node<T>* temp1, *temp2, *result_head=NULL,*result_temp=NULL;
	temp1=head1;
	temp2 = head2;

	stack <Node<T>* > s1, s2;
	while(temp1!=NULL)
	{
		s1.push(temp1);
		temp1 = temp1->next;
	}
	while(temp2!=NULL)
	{
		s2.push(temp2);
		temp2 = temp2->next;
	}
	cout<<"Done"<<endl;
	while(s1.empty()==false || s2.empty() == false || buffer_val!=0)
	{
		result_temp = new Node<T>;	
		int a=0,b=0;
		if (s1.empty()==false)
			{
				temp1 = s1.top();
				a = temp1->element;
				s1.pop();
			}
		if(s2.empty()==false)
			{
				temp2 = s2.top();
				b= temp2->element;
				s2.pop();
			}
		cout<<a<<b<<buffer_val<<endl;
		result_temp->element= (buffer_val+a+b)%10;
		buffer_val = (buffer_val+a+b)/10;
		if(result_head	==NULL)
		{
			result_head=result_temp;
		}
		else
		{	
			result_temp->next = result_head;
			result_head = result_temp;
		}
	}
	return result_head;
}


int main()
{
	// cout<<"Hello World";
	string s1,s2;
	cin>>s1;
	cin>>s2;

	vector<int> v1(s1.size()),v2(s2.size());
	for (size_t i =0 ; i<s1.size();i++)
	{
		v1[i] = s1[i]-'0';
	}
	for (size_t i =0 ; i<s2.size();i++)
	{
		v2[i] = s2[i]-'0';
	}
	Node <int> *head_1 = convert_vector_to_linkedlist<int>(v1);
	Node <int> *head_2 = convert_vector_to_linkedlist<int>(v2);
	Node <int> *temp =sum_linkedlist(head_1,head_2);

	// // temp =head;
	while(temp !=NULL)
	{
		cout<<temp->element<<",";
		temp= temp->next;
	}

}