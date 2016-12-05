/*input
21
5 16 3 4 5 2 16 49 10 35 33 14 30 40 22 7 24 38 47 19 42
*/
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int> > isP(std::vector<int> &nums)
{
	sort(nums.begin(),nums.end());
	int sum_val=0;
	size_t n = nums.size();
	for(size_t i = 0 ; i<nums.size();i++)
	{
		sum_val+=nums[i];
	}
    // cout<<"sdfsd"<<endl;
	vector<vector<vector<vector<int>> > > dp(n+1,vector<vector<vector<int>> > (sum_val/2+1));
	

	for(int i =1 ; i <dp.size();i++) //elem
	{
		for(int j = 1; j<dp[0].size();j++)//nums
		{
			dp[i][j] = dp[i-1][j];
			if(j-nums[i-1]==0)
			{
			    vector<int>  temp;
			    temp.push_back(nums[i-1]);
			    dp[i][j].push_back(temp);
			}
			if(j-nums[i-1]>0&&dp[i-1][j-nums[i-1]].size()!=0)
			{
				vector<vector<int> > temp =  dp[i-1][j-nums[i-1]];
				for(size_t k = 0 ; k < temp.size();k++)
				{
				    temp[k].push_back(nums[i-1]);
				    dp[i][j].push_back(temp[k]);
					
				}
				
			}
		}
	}
	bool exist=true;
	vector<vector<int> >output;
// 	cout<<"here"<<endl;
	for(int i =1 ; i <dp.size()&&exist;i++) //elem
	{
		for(int j = 1; j<dp[0].size()&&exist;j++)
		{
			// cout<<dp[i][j].size()<<" ";
			for(int k = 0 ; k < dp[i][j].size()&&exist;k++)
			{
				if((sum_val*dp[i][j][k].size())==j*n)
				{
					// cout<<sum_val<<" "<<i<<" "<<j<<" "<<dp[i][j][k]<<endl;
				// 	cout<<dp[i][j][k].size()<<endl;
					output.push_back(dp[i][j][k]);
					exist=false;
				}
			}
		}
		// cout<<endl;
	}
	// cout<<sum_val<<n<<dp[3][5][0]<<endl;
// 	cout<<output.size()<<endl;
    int index=0;
    if(output.size()==0)
    return output;
    vector<int> fir = output[0];
    for(size_t i = 0 ; i< fir.size();i++)
    {
        std::vector<int>::iterator position = std::find(nums.begin(), nums.end(), fir[i]);
        if (position != nums.end()) // == myVector.end() means the element was not found
            nums.erase(position);
        // nums.remove(fir[i]);
        
    }
    output.push_back(nums);
    return output;

}

bool isPossible(std::vector<int> &nums)
{
	sort(nums.begin(),nums.end());
	int sum_val=0;
	size_t n = nums.size();
	for(size_t i = 0 ; i<nums.size();i++)
	{
		sum_val+=nums[i];
	}

	vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (sum_val/2+1));
	for(size_t i = 0 ; i<=n;i++)
	{
		dp[i][0] = vector<int>({0});
	}

	for(int i =1 ; i <dp.size();i++) //elem
	{
		for(int j = 1; j<dp[0].size();j++)//nums
		{
			dp[i][j] = dp[i-1][j];
			if(j-nums[i-1]>=0&&dp[i-1][j-nums[i-1]].size()!=0)
			{
				vector<int> &temp =  dp[i-1][j-nums[i-1]];
				for(size_t k = 0 ; k < temp.size();k++)
				{
					dp[i][j].push_back(temp[k]+1);
				}
			}
		}
	}
	bool exist=false;
	for(int i =1 ; i <dp.size();i++) //elem
	{
		for(int j = 1; j<dp[0].size();j++)
		{
			// cout<<dp[i][j].size()<<" ";
			for(int k = 0 ; k < dp[i][j].size();k++)
			{
				if((sum_val*dp[i][j][k])==j*n)
				{
					// cout<<sum_val<<" "<<i<<" "<<j<<" "<<dp[i][j][k]<<endl;
					exist=true;
				}
			}
		}
		// cout<<endl;
	}
	// cout<<sum_val<<n<<dp[3][5][0]<<endl;
	return exist;

}



int main()
{
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin>>nums[i];
	}
	// cout<<nums.size()<<endl;
	// cout<<isPossible(nums);
	isP(nums);
}