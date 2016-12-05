/*input
6
1 2 3 4 5 6 
*/
#include <iostream>
#include <stack>
#include <vector>
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
treeNode<T> * array_to_tree(T *arr, int l, int r)
{
	treeNode<T> *temp;
	if (arr[l] == -1 or l >r )
	return NULL;

	temp = new treeNode<T>(arr[l]);
	temp->left =array_to_tree(arr,2*(l+1)-1,r);
	temp->right = array_to_tree(arr,2*(l+1),r);
	// cout<<temp->element;
	return temp;

};
template <class T>
void postorder (treeNode<T>* &tree)
{	if(tree !=NULL)
	{
		
		postorder((tree)->left);
		cout<<tree->element;
		postorder((tree)->right);
		
		
	}
}
template <class T>
int inorder_successor_util(treeNode<T> *root,int &element, bool &output)
{
	if(!root)
		return -1;
	int left,right;
	left = inorder_successor_util<T>(root->left, element, output);
	if(left !=-1)
		return left;
	if(output)
		return root->element;
	if(root->element==element)
	{
		output = true;
	}
	right = inorder_successor_util<T>(root->right,element,output);
	
	return right;

}
template <class T>
int inorder_successor(treeNode<T> *root,int element)
{
	bool output(false);
	return inorder_successor_util<T>(root,element,output);
}
int main()
{
	treeNode <int> *root;

	int arr_tree[MAXN];
	int n;
	cin>>n;
	for(int i =0; i<n;i++)
	{
		cin>>arr_tree[i];
	}
	// for(int i =0; i<n;i++)
	// {
	// 	cout<<arr_tree[i];
	// }
	root = array_to_tree<int>(arr_tree,0,n-1);
	if (root ==NULL)
	{
		cout<<"NULL";
	}
	cout<<inorder_successor<int>(root,3)<<endl;
	postorder(root);

}