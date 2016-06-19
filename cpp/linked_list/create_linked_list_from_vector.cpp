/*input
abcdedfghi
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
struct node {T element; node<T> * next;
	

	node (T &theelement)
	{
		element = theelement;
		next =NULL;	
	}
};

template<class T>
node<T> * convert_vector_to_linkedlist(vector<T> &vec)
{
	size_t size = vec.size();
	node<T> *temp=NULL,*head=NULL,*tail=NULL;
	if (size == 0)
	{
		return head;
	}

	for (size_t i =0; i<size;i++)
	{
		temp = new node<T>(vec[i]);
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
	string s1;
	cin>>s1;

	vector<char> v1(s1.begin(),s1.end());
	node <char> * head = convert_vector_to_linkedlist<char>(v1);
	node <char> *temp =NULL;

	temp =head;
	while(temp !=NULL)
	{
		cout<<temp->element<<",";
		temp= temp->next;
	}

}