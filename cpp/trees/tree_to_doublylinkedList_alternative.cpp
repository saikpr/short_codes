/*input
6
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
treeNode<T> *tree_to_DLL(treeNode<T> *root)
{

	treeNode<T> *new_root=NULL;
	if(root ==NULL)
		return new_root;
	// cout<<"Root"<<root->element<<endl;
	treeNode<T> *left_node = tree_to_DLL(root->left), *right_node = tree_to_DLL(root->right);
	root->left = NULL;
	root->right = NULL;
	treeNode<T> *last_elem = NULL;
	if(left_node ==NULL)
	{
		new_root = root;
		last_elem = root;
	}
	else
	{
		new_root = left_node;
		last_elem = left_node;
		while(last_elem->right !=NULL)
		{
			last_elem = last_elem->right;
		}
		last_elem ->right = root;
		root->left = last_elem;
		last_elem = root;
	}

	last_elem ->right = right_node;
	if (right_node!=NULL)
	right_node->left = last_elem;
	return new_root;
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
	// postorder<int>(root1);
	// cout<<"Here";
	treeNode <int>  *new_root = tree_to_DLL<int> (root1);
	// treeNode <int> *temp;

	// temp = root1;
	// cout<<root1->element<<endl;
	// do{	
	// 	cout<<temp->element;
	// 	temp=temp->right;
	// }while(temp != root1);
	
}