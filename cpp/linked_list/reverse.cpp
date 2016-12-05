/*
10
1 2 3 4 5 6 7 8 9 10
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

struct Node {int data; Node * next; Node(int val):data(val),next(NULL){}};

void print_list(Node *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root = root->next;
	}
	return;
}
Node * reverse_list(Node * root)
{
	Node * prev=NULL,*curr = root, * next = root->next;

	while(curr!=NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		if(curr==NULL)
			return prev;
		next =  curr->next;

	}
	return prev;
}
int main()
{
	Node * temp=NULL, *root=NULL,*back=NULL;
	int n;
	cin>>n;
	int t;
	cout<<n<<endl;
	for(int i =0 ; i < n ; i++)
	{
		cin>>t;
		temp = new Node(t);
		if(root ==NULL)
		{
			root = temp;
			back=root;
		}
		else
		{
			back->next = temp;
			back = back->next;

		}
	}
	print_list(root);
	cout<<endl<<"Here"<<endl;
	temp = reverse_list(root);
	print_list(temp);
}