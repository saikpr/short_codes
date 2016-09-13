/*input
1
5 5
769 904 679 866 793
399 235 429 691 723
823 373 489 45 926
348 518 220 504 845
503 125 83 932 28
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;



int hd_val(vector<vector<int> > &M,int i,int j,vector<vector<int> > &isVisit)
{
 isVisit[i][j]=1;
 int R=M.size()-1, C=M[0].size()-1;
 if(i==0 || j==0 || i==R || j==C) 
  return -1; 

 int up_val=M[i-1][j],down=M[i+1][j],left=M[i][j-1],right=M[i][j+1];
 int minall=10001;
 if(isVisit[i-1][j]==0)
  minall=min(minall,up_val);
 if(isVisit[i+1][j]==0)
  minall=min(minall,down);
 if(isVisit[i][j-1]==0)
  minall=min(minall,left);
 if(isVisit[i][j+1]==0)
  minall=min(minall,right);
  
 int mij=M[i][j];
 if(minall>mij)
  return minall-mij;
 else
  if(minall<mij)
   return -1; 
  
 int minup_val=1001,mindown=1001,minleft=1001,minright=1001;
 if(mij==up_val && isVisit[i-1][j]==0) 
  minup_val=hd_val(M,i-1,j,isVisit);
 else
  if(mij!=up_val)
   minup_val=up_val-mij;
 if(mij==down && isVisit[i+1][j]==0) 
  mindown=hd_val(M,i+1,j,isVisit);
 else
  if(mij!=down)
   mindown=down-mij;
 if(mij==left && isVisit[i][j-1]==0) 
  minleft=hd_val(M,i,j-1,isVisit);
 else
  if(mij!=left)
   minleft=left-mij;
 if(mij==right && isVisit[i][j+1]==0)  minright=hd_val(M,i,j+1,isVisit);
 else
  if(mij!=right)
   minright=right-mij;
 if(minup_val<0 || minleft<0 || mindown<0 || minright <0) 
  return -1; 
  int min1=min(minup_val,mindown);
  int min2=min(minleft,minright);
  minall=min(min1,min2);
  return minall;
}
int get_water_sum(vector<vector<int> > M)
{
 int row=M.size();
 int col=M[0].size();
 int total=0;
 int nexthold=0;
 bool flag_test=false;
 while(1)
 {
  flag_test=false;
  for(int i=0;i<row;i++)
  {
   for(int j=0;j<col;j++)
   {
    
    vector<vector<int> > isVisit;
    isVisit=vector<vector<int> >(M.size(), vector<int>(M[0].size(),0));
    nexthold=hd_val(M,i,j,isVisit);
    if(nexthold>0)
    {
     flag_test=true;
     M[i][j]+=nexthold;//fill current cell up_val to the maxhold
     total+=nexthold;
    }
   }
  }
  if(!flag_test)
   break;
 }
 // for(int i=0;i<row;i++)
 //  {
 //   for(int j=0;j<col;j++)
 //   {
 //    cout<<M[i][j]<<" ";
 //   }cout<<endl;
 // }
 return total;
}

int main()
{
  int T;
  cin>>T;
  for (size_t i =0;i<T;i++)
  {
    int R,C;
    cin>>R>>C;
    std::vector<vector<int>> vec(R,vector<int>(C,0));

    for (size_t j =0 ;j <R;j++)
    {
      for (size_t k = 0; k<C; ++k)
      {
        cin>>vec[j][k];
        // cout<< vec[j][k];
      }
    }
    cout<<"Case #"<<i+1<<": ";
    cout<<get_water_sum(vec)<<endl;
  }
}