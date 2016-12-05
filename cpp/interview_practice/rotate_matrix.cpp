/*input
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void rotate(vector<vector<int> > &arr);

void print_matrix(vector<vector<int> > &arr)
{
	int n = arr.size();
	// cout<<n<<endl;
	for(size_t i = 0 ; i < n ; i++)
	{
		for(size_t j = 0 ; j < n; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
int main()
{	
	int n;
	cin>>n;
	vector<vector<int> > arr(n,vector<int>(n,0));
	for(size_t i = 0 ; i < n ; i++)
	{
		for(size_t j = 0 ; j < n; j++)
		{
			cin>>arr[i][j];
		}
	}
	rotate(arr);
	print_matrix(arr);
	return 0;

}
void rotate(vector<vector<int> > &arr)
{
	int n = arr.size();
	int l = n-1;
	int temp;

	for(int elem=0 ; elem<(n+1)/2;elem++)
	{
		for(int layer=0;layer<(n)/2;layer++)
		{
			temp = arr[layer][elem];
			arr[layer][elem] = arr[l-elem][layer];
			arr[l-elem][layer] = arr[l-layer][l-elem];
			arr[l-layer][l-elem] = arr[elem][l-layer];
			arr[elem][l-layer] = temp;
			// print_matrix(arr);
			// cout<<layer<<" "<<elem<<endl;
			
		}

	}
	return;
}