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

template<class T>
void sum_path(treeNode <T>* &root, T sum = 0, int index = 1)
{
	unordered_map<int, int > hashmap;
	// T cumsum=0;
	queue<tuple<treeNode <T> * , int, T> > q1;

	q1.push(make_tuple(root,index,root->element));
	

	while(!q1.empty())
	{	
		tuple<treeNode <T> * , int, T>  temp = q1.front();
		q1.pop();
		cout<<get<1>(temp)<<" "<<get<2>(temp)<<endl;
		try{
			int temp_sum = get<2>(temp)- sum ;
			cout<<"check :"<<get<2>(temp)<<temp_sum<<endl;
			int othr_index = hashmap.at(temp_sum);
			int child = get<1>(temp);
			while (child>0)
			{	
				 if (child == othr_index )
					cout<<"Found "<<get<1>(temp)<<" "<<get<2>(temp)<<" "<<temp_sum<<" "<<hashmap.at(temp_sum)<<endl;
				child = child/2;
			}
		}
		catch(out_of_range)
		{
			// continue;
		}

		hashmap[get<2>(temp)] = get<1>(temp);

		if (get<0>(temp)->left)
			q1.push(make_tuple(get<0>(temp)->left,2*(get<1>(temp)),get<2>(temp)+get<0>(temp)->left->element));
		if (get<0>(temp)->right)
			q1.push(make_tuple(get<0>(temp)->right,2*(get<1>(temp))+1,get<2>(temp)+get<0>(temp)->right->element));


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

	sum_path(root1,7);



}