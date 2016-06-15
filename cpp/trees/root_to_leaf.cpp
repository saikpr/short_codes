/*input
10
1 2 3 4 5 6 7 -1 9 10
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
void rootToLeaf(treeNode<T>* &tree,vector<T> &v)
{
	if (tree->left!=NULL||tree->right!=NULL)
	{
		v.push_back(tree->element);
		if (tree->left)
		{rootToLeaf(tree->left,v);
		}
		if(tree->right)
		{rootToLeaf(tree->right,v);
		}
		v.pop_back();
	}
	else
	{
		int i=0;
		while(i<v.size())
		{	
			cout<<v[i++]<<",";
		}
		cout<<tree->element<<endl;
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
	vector<int> v1;

	rootToLeaf(root1,v1);
}