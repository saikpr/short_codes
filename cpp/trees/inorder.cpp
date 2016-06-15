#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template <class T>
struct treeNode {
	T element;
	treeNode<T> *left;
	treeNode<T> *right;

	treeNode()
	{
		left= right= NULL;
	}
	treeNode(T &theElement)
	{
		element = theElement;

	}
	treeNode( T &theElement,treeNode<T> *theLeft, treeNode<T> *theRight)
	{
		element = theElement;

		left = theLeft;
		right = theRight;
	}
};


template<class T>
void inorder(treeNode<T> *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->element;
		inorder(root->right);
	}
}

int main()
{
	treeNode<int> *root=NULL;
	int val = 1;
	root = new treeNode<int>(val);
	val++;
	root ->left = new treeNode<int>(val);
	val++;
	root ->right = new treeNode<int>(val);

	inorder(root);
}