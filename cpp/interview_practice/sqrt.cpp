/*input
9
1 4 9 16 33 47 

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



double sqrt(int A) {
    long double x=1;
    

    if (A==1 or A==0)
    return A;
	int kmax = 100;
	// cout<<A<<x<<endl;
    while(1)
    {	
    	kmax--;
    	// cout<<x*x<<" "<<(long double)A<<endl;
    	if(kmax<0 )
    		break;
    	// if(x*x<=(long double)A&&(long double)A<(x+1)*(x+1))
    	// 		break;
        x = (x + (long double)A/x)/2;
        // cout<<"x"<<x<<endl;
    }
    // cout<<x<<endl;
    return (int)x;
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for (size_t i = 0; i < n;i++)
	{
		cin>>vec[i];
	}
	// for (size_t i = 0; i < n;i++)
	// {
	// 	cout<<vec[i]<<" "<<sqrt(vec[i])<<endl;
	// }
	cout<<sqrt(308634616)<<endl;

}
