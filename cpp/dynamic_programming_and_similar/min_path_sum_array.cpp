/*input
3 3
1 2 3
4 5 6
7 8 9
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

int minPathSum(vector<vector<int>>& grid) {
    int sum = 0 ;
    int m = grid.size();
    int n=1;
    //return m;
    if (m>0)
        n = grid[0].size();
    //return n;
    vector <vector <int>  > a1;
    a1.resize(m);
    for (int i=0;i<m;i++)
    {a1[i].resize(n);
        for (int j=0;j<n;j++)
       
        {
            a1[i][j] = 0;
            
        }
    }
    a1[0][0] = grid [0][0];
    for (int i=1;i<n;i++)
    {
        a1[0][i]= a1[0][i-1]+grid[0][i];
    }
    for (int i=1;i<m;i++)
    {
        a1[i][0]= a1[i-1][0]+grid[i][0];
    }
    for(int i=1;i<m;i++)
    {
        for (int j =1 ; j<n; j++)
        {
            a1[i][j] = min(a1[i-1][j],a1[i][j-1])+grid[i][j];
        }
    }
    return a1[m-1][n-1];
}


int main()
{
    vector<vector<int>> v1;
    int m,n;
    cin>>m>>n;
    v1.resize(m);
    for (int i=0;i<m;i++)
    {
        v1[i].resize(n);
        fill(v1[i].begin(),v1[i].end(),0);

    }
    for (int i =0;i<m;i++)
    {
        for (int j=0;j<n ; j++)
        {
            cin>>v1[i][j];
        }
    }
    cout<<minPathSum(v1);
}