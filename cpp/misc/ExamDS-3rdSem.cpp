#include<iostream>
using namespace std;
int arr2[100],term=0;


int postorder(int arr[],int arr1[],int l,int m, int k, int p)
{
	int root =-1,x,y;
	if (l==m)
		{
			arr2[term]=arr[l];
			term++;
			
			
		}
	else if(l<m)
		{
		
			root =arr[l];
			arr2[term]=root;
			term++;
			
			
			for(int i=l;i<=m;i++)
			{
				if (arr1[i]==root)
					{x=i;
					break;
					
					}
			}
			
			
			
			int max=l;
			for(int i=k;i<x;i++)
				{
					for(int j=l;j<=m;j++)
						{
							if(arr1[i]==arr[j])
								{
									if(max<=j)
										{max=j;
										
										}
								}
						}
				}
			y=max;
			postorder(arr,arr1,y+1,m,x+1,p);
			postorder(arr,arr1,l+1,y,k,x-1);
		}
			
			
		
}





int main()
{
	int arr[100],arr1[100],l=0,k=0,n,m,p;
	cout<<"Enter the Number of nodes:";
	cin>>n;
	m=n;
	p=n;
	cout<<"\nEnter the Values for preorder in numeric value followed by space";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nEnter the Values for inorder in numeric value followed by space";
	for(int i=0;i<n;i++)
		cin>>arr1[i];
		
	postorder(arr,arr1,l,m,k,p);
	cout<<"\n\n\n\nPrinting the values for tree in PostOrder";
	
	while(term>0)
	{cout<<arr2[term-1]<<'\t';
		term = term -1;
	}








}
