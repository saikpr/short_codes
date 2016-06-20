/*input
8
*/
#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#define MAXN 100
using namespace std;
bool check_symmetry(vector<vector <bool> > &v1, int max_queens)
{	int reverse = max_queens;
	for (size_t i = 0;i<max_queens/2;i++)
	{
		
	}
}
void print_board (vector<vector <bool> > &v1)
{	
	int max_queens = v1.size();
	for (size_t i =0; i <max_queens;i++)
	{
		for (size_t j =0; j <max_queens;j++)
		{
			if (v1[i][j])
			{
				cout<<"Q ";
			}
			else
			{
				cout<<"- ";
			}
		}	
		cout<<endl;
	}
}

bool check_validpos(vector<vector <bool> > &v1, int row , int colm,int max_queens)
{	assert(v1.size() == max_queens);
	int check_row = row, check_colm = colm;

	for(size_t i =0;i<max_queens;i++)
	{
		if (v1[row][i]==true||v1[i][colm]==true)
			return false;
	}
	while(check_colm>=0 && check_row>=0)
	{
		if (v1[check_row--][check_colm--]==true)
			return false;
	}
	check_row = row; check_colm = colm;
	while(check_colm>=0 && check_row<max_queens)
	{
		if (v1[check_row++][check_colm--]==true)
			return false;
	}
	check_row = row; check_colm = colm;
	while(check_colm<max_queens && check_row>=0)
	{
		if (v1[check_row--][check_colm++]==true)
			return false;
	}
	// cout<<'h'<<endl;
	check_row = row; check_colm = colm;
	while(check_colm < max_queens && check_row < max_queens)
	{
		if (v1[check_row++][check_colm++]==true)
			return false;
	}
	return true;
}

bool nqueens (vector<vector <bool> > &v1, int queens_done, int &max_queens)
{	

	if (max_queens == queens_done)
	{
		cout<<"Done"<<endl;
		// return true;
		print_board(v1);
	}
	else
	{
		vector <bool> possible_candidates(max_queens,false);
		for (int i=0;i<max_queens;i++)
		{
			possible_candidates[i] = check_validpos(v1,queens_done,i,max_queens);
			// cout<<queens_done<<i<<possible_candidates[i]<<endl;
		}
		for (int i=0;i<max_queens;i++)
		{	
			if (possible_candidates[i] == true)
			{	
				// cout<<"Putting Queen at"<<queens_done<<i<<endl;
				v1[queens_done][i]=true;
				bool flag = nqueens(v1,queens_done+1,max_queens);
				if (flag == false)
				{
					v1[queens_done][i] = false;

				}
				else
				{
					return true;
				}
			}
		}
	}
}


int main()
{
	int max_queens;
	cin>>max_queens;
	vector<vector <bool> > v1(max_queens,vector<bool>(max_queens,false));
	bool exist = nqueens(v1,0,max_queens);
	// if (exist ==false)
	// {
	// 	cout<<"No Solution";
	// 	return 0;
	// }
	// print_board(v1);
}