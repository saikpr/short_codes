/*input
9
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

vector<string> print_board (vector<vector <bool> > &v1)
{	
	int max_queens = v1.size();
	vector<string> to_return;
	for (size_t i =0; i <max_queens;i++)
	{
		string temp;
		for (size_t j =0; j <max_queens;j++)
		{
			if (v1[i][j])
			{
				temp+="Q";
			}
			else
			{
				temp+=".";

			}
		}	
		to_return.push_back(temp);
	}
	return to_return;
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

bool nqueens (vector<vector <bool> > &v1, int queens_done, int &max_queens,vector<vector<string> > &to_return_final)
{	

	if (max_queens == queens_done)
	{
		// cout<<"Done"<<endl;
		// return true;
		vector<string> t = print_board(v1);
		to_return_final.push_back(t);
		// return true;
		
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
				bool flag = nqueens(v1,queens_done+1,max_queens,to_return_final);
				// cout<<flag<<endl;
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
		return false;
	}
}


int main()
{
	int max_queens=9;
	// cin>>max_queens;
	vector<vector <bool> > v1(max_queens,vector<bool>(max_queens,false));
	vector<vector<string> > to_return_final;
	bool exist = nqueens(v1,0,max_queens,to_return_final);
	for(size_t i = 0 ; i<to_return_final.size();i++)
	{
		for(size_t j = 0 ; j < to_return_final[i].size();j++)
		{
			cout<<to_return_final[i][j]<<endl;
		}
		cout<<"Done"<<endl;
	}
	// if (exist ==false)
	// {
	// 	cout<<"No Solution";
	// 	return 0;
	// }
	// print_board(v1);
}