/*input
10
1 2 3 4 5 6 7 -1 9 10
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
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
void print_kth_distance (treeNode<T>* &root, int k )
{
	queue<pair<treeNode<T>*,int> >  q1;
	if (root==NULL)
		return;
	q1.push(make_pair(root,0));
	pair <treeNode<T>*,int> temp;
	while(!q1.empty())
	{
		temp = q1.front();
		q1.pop();
		if (temp.second == k)
			cout<<temp.first->element<<" ";
		if (temp.first->left)
			q1.push(make_pair(temp.first->left,temp.second+1));
		if (temp.first->right)
			q1.push(make_pair(temp.first->right,temp.second+1));
	}
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
	print_kth_distance(root1,3);
}