/*input
7
1 -1 3 -1 -1 6 7 -1 9 10
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
struct treeNode 
{
	T element;
	treeNode<T> *left, *right;

	treeNode (T &theElement)
	{
		element = theElement;
		left =NULL;right =NULL;
	}

};

template <class T>
void array_to_tree(treeNode<T>* &root,T *arr, int l, int r)
{
	treeNode<T> *temp;
	if (arr[l] == -1 or l >r )
	{root =  NULL;return;}

	temp = new treeNode<T>(arr[l]);
	array_to_tree(temp->left,arr,2*(l+1)-1,r);
	array_to_tree(temp->right,arr,2*(l+1),r);
	// cout<<temp->element;
	root = temp;
	return;

};
template <class T>
void postorder (treeNode<T>* &tree)
{	if(tree !=NULL)
	{
		cout<<tree->element;
		postorder((tree)->left);

		postorder((tree)->right);
		
	}
}

template <class T>
treeNode<T> ** D_linkedlists(treeNode<T>* &root, int &max_height)
{
	// treeNode<T> * temp;
	queue<pair<treeNode<T>*, int> > q1;
	stack<pair<treeNode<T>*, int>  > s1;

	q1.push(make_pair(root,0));
	s1.push(make_pair(root,0));
	while (!q1.empty())
	{
		pair<treeNode<T>*, int> temp = q1.front();
		q1.pop();
		if (temp.first->left)
		{
			q1.push(make_pair(temp.first->left,temp.second+1));
			s1.push(make_pair(temp.first->left,temp.second+1));
		}
		if (temp.first->right)
		{
			q1.push(make_pair(temp.first->right,temp.second+1));
			s1.push(make_pair(temp.first->right,temp.second+1));
		}

	}
	int present_height = s1.top().second;
	max_height = present_height;
	// cout<<present_height<<endl;
	treeNode<T>** temp = new treeNode<T>*[present_height+1];
	// int present_height = 0;
	while(!s1.empty())
	{	
		// cout<<s1.size()<<endl;
		pair<treeNode<T>*, int> temp_pair = s1.top();
		// cout<<temp_pair.first->element<<endl;

		s1.pop();
		present_height = temp_pair.second;

		(*(temp+present_height))=temp_pair.first;
		// cout<<"height"<<present_height<<endl;

		temp_pair.first->right =NULL;
		// cout<<"height"<<present_height<<endl;
		while(!s1.empty() && s1.top().second == present_height)
		{	
			s1.top().first->right=(*(temp+present_height));
			(*(temp+present_height)) = s1.top().first;
			s1.pop();
		}

	}

	return temp;
}

int main()
{
	treeNode <int> *root1;

	int arr_tree[MAXN];
	int n;
	cin>>n;
	for(int i =0; i<n;i++)
	{
		cin>>arr_tree[i];
	}
	array_to_tree<int>(root1,arr_tree,0,n-1);
	int max_height = 0;
	treeNode<int> **temp = D_linkedlists(root1,max_height);
	treeNode<int> *temp1 =NULL;
	// if (temp == NULL)
	// {cout<}
	// cout<<max_height;
	for (int i =0;i<=max_height;i++)
	{
		temp1 = *(temp+i);

		while (temp1!= NULL)
		{
			cout<<temp1->element<<",";
			temp1 = temp1->right;
		}
		cout<<endl;
	}




}