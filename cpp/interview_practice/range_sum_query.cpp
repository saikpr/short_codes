/*input
5
0 9 5 7 3
1 4 4
*/

/*
[0,9,5,7,3]
[1,1,1,0,0,0,1,0,1,0]
[[4,5],[1,7],[0,8],[1,9],[3,4]]
[[4,4],[2,4],[3,3],[1,2],[4,4]]
*/
#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;


class NumArray {
private:
    vector<int> range_sum_values;
    vector<pair<int, int > > ranges;
public:
    int get_parent(int val)
    {
        return (val+1)/2-1;
    }
    int get_first_child(int val)
    {
        return (val+1)*2 -1;
    }
    void print_tree()
    {
        for(size_t i = 0 ; i <ranges.size();i++ )
        {
            cout<<i<<" "<<range_sum_values[i]<<" "<<ranges[i].first<<" "<<ranges[i].second<<endl;
        }
        cout<<endl;
    }
    NumArray(vector<int> &nums) {
        
        int bits=0;
        int n = nums.size();
        int temp;
        
        temp = n ; 
        
        while(n>(1<<bits))
        {
            bits++;
            
        }
        // cout<<"Bits :"<<bits<<endl;
        int length = ((1<<(bits+1) )-1 );
        range_sum_values = vector<int>(length,0);
        ranges = std::vector<pair<int,int> >(length,make_pair(-1,-1));

        for(size_t i = 0 ; i < nums.size();i++)
        {
            range_sum_values[i+length/2] = nums[i];
            ranges[i+length/2] = make_pair(i,i);
        }
        for(size_t i = nums.size()+length/2 ; i < ranges.size();i++)
        {
            ranges[i] = make_pair(i-length/2,i-length/2); 
        }
        for(int i = length/2-1;i>=0;i--)
        {
            range_sum_values[i] = range_sum_values[get_first_child(i)]+range_sum_values[get_first_child(i)+1];
            ranges[i] = make_pair(ranges[get_first_child(i)].first,ranges[get_first_child(i)+1].second);
        }

        print_tree();
        // cout<<length<<endl;

        
    }

    void update(int i, int val) {
        // return;
        stack <int> indexs ;

        int ind = 0;
        int mid;
        indexs.push(ind);
        while(ranges[ind]!= make_pair(i,i))
        {
            mid = ranges[ind].first + ranges[ind].second;
            mid = mid/2;
            if (i<=mid)
            {
                ind = get_first_child(ind);
            } 
            else
            {
                ind = get_first_child(ind) +1;
            }
            indexs.push(ind);
        }
        int diff = val - range_sum_values[ind];
        while(indexs.empty()==false)
        {
            range_sum_values[indexs.top()] +=diff;
            indexs.pop();
        }
        // cout<<ind<<endl;
        // print_tree();
    }
    int sumrange_recurse(pair<int,int> &rang,int ind)
    {

        int mid = ranges[ind].first+ranges[ind].second;
        mid = mid/2;
        // cout<<ind<<" "<<mid<<endl;
        int left_value = 0, right_value = 0 ;
        if(rang.first <=ranges[ind].first && rang.second>= ranges[ind].second) //full overlap
        {
            return range_sum_values[ind];
        }
        if (rang.second < ranges[ind].first || rang.first > ranges[ind].second) // no overlap
        {
            return 0;
        }
        if (rang.first<=mid)
        {
            left_value = sumrange_recurse(rang,get_first_child(ind));
        }
        if (rang.second>=mid)
        {
            right_value= sumrange_recurse(rang,get_first_child(ind)+1);
        }

        return left_value+right_value;
    }
    int sumRange(int i, int j) {
        pair<int,int> temp = make_pair(i,j);
        return sumrange_recurse(temp,0);
    }
};


int main()
{
    int n; 
    cin>>n;
    vector<int> nums(n);
    for(int i = 0 ; i <  n ; i++)
    {
        cin>>nums[i];
    }
    NumArray numArray(nums);
    cout<<"Created"<<endl;
    while(cin.eof()==false)
    {
        int q,i,j;
        cin>>q>>i>>j;
        cout<<"Processing " <<q<<" "<<i<<" "<<j<<endl;
        switch(q)
        {
            case 1:
                    cout<<numArray.sumRange(i,j)<<endl;
                    break;
            case 2:
                    numArray.update(i,j);
                    break;
        }
       
    }

}

