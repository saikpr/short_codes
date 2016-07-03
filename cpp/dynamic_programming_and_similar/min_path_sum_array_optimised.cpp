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
    vector<int> dist(n+1,0);

    dist[0]=grid[0][0];
    for (int i=1;i<n;i++)
    {
        dist[i]=grid[0][i]+dist[i-1];
    }


    for (int i =1; i<m;i++)
    {   dist[0] = dist[0] + grid[i][0];
        for (int j=1;j<n;j++)
        {
            dist[j]= min(dist[j-1], dist[j]) + grid[i][j];
        }

    }
    // cout<<dist[n-1];
    return dist[n-1];
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
    cout<<minPathSum(v1)<<endl;
}