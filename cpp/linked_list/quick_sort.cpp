/*input
54134324234324235990284923749273940
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
struct Node {T data; Node<T> * next;
	

	Node (T &thedata)
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
Node<T>* quick_sort(Node<T> * &head)
{	
	if(head ==NULL || head->next ==NULL)
		return head;
	Node <T> *temp_M =head;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<endl;
	Node<T> *temp1=NULL, *temp2=NULL, *temp_mov=NULL, *temp_next=NULL;
	temp_mov = head;
	T partition = temp_mov->data;
	temp_mov  = temp_mov->next;
	// cout<<partition<<endl;
	while(temp_mov != NULL)
	{	
		// cout<<"temp_mov"<<temp_mov->data<<endl;
		if (temp_mov->data <partition)
		{
			if(temp1 ==NULL)
			{
				temp1 = temp_mov;
				temp_mov = temp_mov ->next;
				temp1->next= NULL;

			}
			else
			{	
				temp_next = temp_mov->next;
				temp_mov ->next = temp1;
				temp1 = temp_mov;
				temp_mov = temp_next;

				
			}//inner if
		}//outer if

		else if (temp_mov->data >=partition)
		{
			if(temp2 ==NULL)
			{
				temp2 = temp_mov;
				temp_mov = temp_mov ->next;
				temp2->next= NULL;

			}
			else
			{	
				temp_next = temp_mov->next;
				temp_mov ->next = temp2;
				temp2 = temp_mov;
				temp_mov = temp_next;

				
			}//inner -else
		}//outer-else
	}//whil
	// temp_M =temp1;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<endl;
	// temp_M =temp2;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<endl;
	// cout<<"Done"<<partition<<endl;
	temp1 = quick_sort(temp1);
	
	temp2 = quick_sort(temp2);
	// temp_M =temp1;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<"Done 11 "<<partition<<endl;
	// temp_M =temp2;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<endl;
	// cout<<"Done 12 "<<partition<<endl;
	temp_next = NULL;
	temp_next =temp1;
	while(temp1!=NULL&& temp_next->next !=NULL )
	{
	temp_next = temp_next->next;

	}
	if(temp_next!=NULL)
		temp_next->next = head;
	head->next = temp2;
	if(temp_next!=NULL)	
		head =temp1;
	// cout<<"Before Returning"<<partition<<endl;
	// temp_M =head;
	// while(temp_M !=NULL)
	// {
	// 	cout<<temp_M->data<<",";
	// 	temp_M= temp_M->next;
	// }
	// cout<<endl;
	// cout<<"Now Returning"<<endl;
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
	Node <int> *head_1 = convert_vector_to_linkedlist<int>(v1);
	Node <int> *temp =quick_sort(head_1);

	while(temp !=NULL)
	{
		cout<<temp->data<<",";
		temp= temp->next;
	}

}

