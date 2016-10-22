/*input
71045970
41535484
64735492
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
using namespace std;

int pow(int x, int n, int d)
 {
 	
    if(n==0&&x==0)
     return 0;
    if(n==0)
     return 1;
    if (n==1)
    	{if (x <0)
        x +=d;
    	    return x%d;}
    bool is_odd=false;
    if (n%2==1)
    {
    	is_odd=true;
    }
    
    int k = n/2;

    long long  val = pow(x%d,k,d);
    // cout<<"val"<<x<<" "<<n<<" "<<d<<" ";
    // cout<<val<<" ";
    long long to_return = (((val%d)*(val%d))%d)*((is_odd)?x:1);
    // cout<<to_return<<endl;
    if (to_return <0)
        to_return +=d;
    // cout<<x<<" "<<n<<" "<<d<<" ";
    // cout<<to_return <<endl;

    return to_return%d;
}

int main()
{
	int x,n,d;
	cin>>x;
	cin>>n;
	cin>>d;
	cout<<pow(x,n,d);
}