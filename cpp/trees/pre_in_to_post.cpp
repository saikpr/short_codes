/*input
6
4 2 5 1 3 6
1 2 4 5 3 6
*/
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct treeNode 
{
 	int element; 
	treeNode *left,*right;
}
;
void create_tree(treeNode* &root, int in[], int pre[], int l_in, int r_in, int l_pre, int r_pre)
{	
	// cout<<l_in<<r_in<<l_pre<<r_pre<<endl;
	if(l_in>r_in)
		return;
	if (l_in==r_in)
	{	treeNode *temp = new treeNode;
		temp = new treeNode;
		temp->element = pre[l_pre];
		temp->left=temp->right =NULL;
		root = temp;
		// cout<<"t"<<temp->element<<endl;
		return;
	}
	int rootel = pre[l_pre];
	int i = l_in;
	while(in[i++] != rootel && i<=r_in)
	{}
	i--;
	// cout<<l_in<<r_in<<l_pre<<r_pre<<i<<endl;
	treeNode *temp = new treeNode;
	// (*root) = new treeNode ;
	temp->element = rootel;
	// cout<<l_pre<<"left"<<endl;
	// if ()
	create_tree ((temp->left),in,pre,l_in,i-1,l_pre+1,l_pre+(i-l_in));
	// cout<<l_pre<<"right"<<endl;
	create_tree((temp->right), in,pre,i+1,r_in,l_pre+(i-l_in) +1,r_pre);
	root = temp;
	// cout<<"t"<<(*root)->element<<endl;
	return;
}	

void postorder (treeNode* tree)
{	if(tree !=NULL)
{
	
	postorder((tree)->left);
	postorder((tree)->right);
	cout<<tree->element;
}
}

int main()
{
	int n;
	cin>>n;
	int in[n],pre[n];
	for (int i =0;i<n;i++)
	{
	cin>>in[i];
	}
	for (int i =0;i<n;i++)
	{
	cin>>pre[i];
	}
	// for (int i =0;i<n;i++)
	// {
	// 	cout<<in[i]<<pre[i];
	// }
	treeNode *root=NULL;
	create_tree(root,in,pre, 0, n-1,0,n-1);
	if(root ==NULL)
		{cout<<"null";}
	treeNode *pr;
	pr=root;
	postorder(root);
	

}
