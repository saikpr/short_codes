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
bool identical_check (treeNode<T>* &tree1, treeNode<T>* &tree2)
{	
	if(tree1 == NULL && tree2 == NULL)
		{
			// cout<<"NUL";
			return true;
		}
	else if(tree1 ==NULL || tree2 == NULL)
		return false;
	// cout<<tree1->element<<" "<<tree2->element<<endl;
	if (tree1->element != tree2->element)
		return false;
	
	bool t1 = identical_check(tree1->left,tree2->left);
	bool t2 = identical_check(tree1->right,tree2->right);
	// cout<<t1<<t2<<endl;
	return t1&t2;
	// cout<<" as"<<t1;
	// return true;
}
int main()
{
	treeNode <int> *root1, *root2;

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
	array_to_tree<int>(root1,arr_tree,0,n-1);
	array_to_tree<int>(root2,arr_tree,0,n-1);
	cout<<identical_check(root1,root2);
	// if (root ==NULL)
	// {
	// 	cout<<"NULL";
	// }
	// postorder(root);

}