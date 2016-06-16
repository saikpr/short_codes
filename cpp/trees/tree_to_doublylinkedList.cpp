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
treeNode<T> * Append(treeNode<T>* &N1,treeNode<T>* &N2)
{		
	if (N1 ==NULL||N2 ==NULL)
		cout<<"sd";
	if (N1== NULL) return N2;
	if (N2 == NULL) return N1;
	treeNode <T> *temp1,*temp2;
	temp1 = N1->left;
	temp2 = N2->left;
	
	temp1->right =N2;
	N2->left = temp1;
	
	temp2->right = N1;
	N1->left =temp2;
	
	

	// cout<<"d"<<endl;
	cout<<"merging"<<N1->right->left->right->element<<N2->left->element<<endl;
	// cout<<"r"<<endl;
	// treeNode <int> *temp=N1;
	// cout<<"output"<<temp->element<<temp->right->element<<(temp->left->left==N1)<<endl;
	// do{	
		// cout<<temp->element;
		// temp=temp->left;
	// }while(temp != N1);
	// cout<<"r"<<endl;
	return N1;
}

template <class T>
treeNode <T> * convertor(treeNode<T>* &root)
{	cout<<"root"<<root->element<<endl;
	if(root ==NULL)
	{
		cout<<"This should not have happened"<<endl;
		return NULL;
	}
	if (root->left ==NULL &&root->right ==NULL)
	{	cout<<"leaf"<<root->element<<endl;
		root->left = root;
		root->right = root;
		return root;
	}
	treeNode<T> *temp=NULL,*temp2=NULL;

	temp = root->left;
	temp2 = root->right;
	root->left = root;
	root->right = root;
	// if(temp)
		temp = convertor<T>(temp);
	// if(temp2)
		temp2 = convertor<T>(temp2);
	cout<<"merge1 "<<temp->element<<temp->right->element<<root->element<<endl;
	// if(temp)
		temp =  Append(temp, root);
	// cout<<temp->element<<temp->right->element<<endl;
	// cout<<temp->element<<endl;
	// cout<<"merge2 "<<temp->element<<temp2->element<<endl;
	// if(temp2)
		temp = Append(temp,temp2);
	// cout<<temp->element<<temp->right->element<<temp->right->right->element<<endl;
	
	cout<<"final"<<temp->element<<endl;
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
	// postorder<int>(root1);
	// cout<<"Here";
	root1 = convertor<int> (root1);
	treeNode <int> *temp;

	temp = root1;
	cout<<root1->element<<endl;
	do{	
		cout<<temp->element;
		temp=temp->right;
	}while(temp != root1);
	
}