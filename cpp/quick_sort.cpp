#include <iostream>
#include <algorithm>
using namespace std;
template <class T,class T_index>
T swap (T *arr,T_index elem1, T_index elem2) //swaps two element with elem1 and elem2 index
{

	T temp=arr[elem1];
	arr[elem1]=arr[elem2];
	arr[elem2]=temp;
}

template <class T,class T_index>
T_index partition( T *arr, T_index BEG, T_index END) //Partitons the array into 2 segment such that x=0,1,2 ... pivot-1, arr[x]<=arr[pivot]
//y=pivot+1,... n-1, n, arr[pivot]<=arr[y]
{	//cout<<"partition"<<BEG<<END<<endl;
	T_index left=BEG;
	T_index right=END;
	T_index pivot=left;

	while (left<right)
	{

		while (arr[right]>=arr[pivot] && right>pivot)
			{right--;}

		swap<T,T_index>(arr,pivot,right);
		pivot=right;

		while (arr[left]<=arr[pivot] && left<pivot)
			{left++;
			}
		swap<T,T_index>(arr,pivot,left);
		pivot=left;

	}
	return pivot;
}
template <class T,class T_index>
int quick_sort(T *arr, T_index BEG, T_index END) // main quick_sort function, divided into 2 pivoted segments and then run the partioning algorithm
{	//cout<<"quick_sort"<<BEG<<END<<endl;
	if(BEG<END)
	{T_index pivot=partition<T,T_index>(arr,BEG,END);
//	cout<<"Pivot Value"<<pivot<<endl;
	quick_sort<T,T_index>(arr,BEG,pivot-1);
	quick_sort<T,T_index>(arr,pivot+1,END);}
	return 0;
}

int main ()
{
	int arr[1000]={0};

	int n;

	cin>>n;
	for (int i=0;i<n;i++)
		{cin>>arr[i];}

	quick_sort<int,int>(arr,0,n-1); //calling quick_sort with max and min index

	for (int i=0;i<n;i++)
	{
		cout << arr[i]<<" ";
	}

}
