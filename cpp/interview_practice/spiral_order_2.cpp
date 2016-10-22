/*input
4
*/

#include <iostream>
#include <stack>
#include <array>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <bitset>
using namespace std;

typedef vector<vector<int> > vvi;


vvi generate_spiral(int n)
{
    vvi solution(n,vector<int>(n,0));

    // int it_i=0,it_j=0;
    int val=1;
    for(int i = 0 ; i <(n+1)/2;i++)
    {
        int j,k,l,m;
        for( j = i;j<n-i;j++)
        {
            solution[i][j] = val++;
        }
        j--;
        for(k = i+1;k<n-i;k++ )
        {
            solution[k][j]=val++;
        }
        k--;
        // cout<<k<<endl;
        for(l= k-1;l>=i;l-- )
        {
            // cout<<l<<endl;
            solution[k][l]=val++;
        }
        l--;
        // cout<<i<<' '<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
        for(m = j-1;m>i;m--)
        {
            solution[m][i]=val++;
        }


    }
    return solution;
}

int main()
{
    int n;
    cin>>n;
    cout<<"hefe"<<endl;
    vvi vec = generate_spiral(n);
    // assert(vec.size()>0&&vec[0].size()>0);
    for(size_t  i = 0 ; i < vec.size();i++)
    {
        for(size_t j =0 ; j < vec[0].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}