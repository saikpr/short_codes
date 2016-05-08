#include <map>
#include <utility>
#include <tuple>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > degree;
    int arr[1500];
    int temp;
    for(int i = 0;i < n ; i++)
    {
       //cout<<"Enter "<<i;
       cin >> temp;
       pair <int,int> pair_temp;
       pair_temp.first=temp;
       pair_temp.second=i+1;
       degree.push_back(pair_temp);
       //acout<<"pushed"<<endl;
    }
    //cout<<"Input Done";

    std::sort(degree.rbegin(), degree.rend()); 
    int k=0;
    bool part_of_tree[1500]={false};

    arr[degree[0].second]=0;
    part_of_tree[degree[0].second]=true;
    for(int i=0;i<n;i++)
    {	k=i+1;
    	//cout<<"this "<<i<<" "<< degree[i].first<<endl;
    	
    	while( degree[i].first!=0)
    	{
    		if (degree[k].first>0 && part_of_tree[degree[k].second]==false)
    		{	//cout<<i<<" "<<k<<" "<<degree[k].second <<endl;
    			//for(int j=0;j<n)
    			degree[k].first--;degree[i].first--;
    			arr[degree[k].second]=degree[i].second;
    			part_of_tree[degree[k].second]=true;
    			k+=1;
				
    		}
    		else
    		{k++;}
    	
    	}
    	//degree[i].first=0;
    }



    for (int i =1;i<=n;i++)
    {
    	cout<<arr[i]<<endl;
    }
    return 0;
}
