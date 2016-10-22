/*input
1
100
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
3
10000 3000 4000 5000
5
3000 100 100 100 100 100
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;


double horner(vector<double> &poly, double x)
{
	int n= poly.size();
	// cout<<n<<x<<endl;
	
    double result = poly[0];  // Initialize result
 	// cout<<result;
    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        {result = result*x + poly[i];
        	// cout<<result;
        }
 	// for (int i=0; i<n; i++)
  //       cout<<poly[i]<<" ";
    // cout<<endl;
    return result;
}


double find_res(vector<double> &poly)
{
	double r_A = 0.0;
	double val_A = horner(poly,r_A);
	// if 
	double precision = 0.000001;
	if (poly.size()>10)
		precision = 0.0001;
	if (poly.size()>20)
		precision = 0.001;
	// cout<<precision;
	double r_B = 2.0;
	double val_B = horner(poly,r_B);
	double r_mid =0.0,val_mid;
	// cout<<std::setprecision (10)<<val_A<<" "<<val_B<<" "<<r_A<<" "<<r_B<<" "<<r_mid<<endl;
	// cout<<std::setprecision (10)<<val_A<<" "<<val_B<<endl;
	// if(val_A*val_B>=0.0)
	// 	{cout<<"this"<<endl;return 1.0;}
	
	while(r_A<r_B)
	{
		val_A = horner(poly,r_A);
		val_B = horner(poly,r_B);

		r_mid = (r_A+r_B)/2;
		if (r_mid == r_B || r_mid==r_A)
			{	
				// cout<<r_A<<" "<<r_B<<" "<<r_mid<<endl;
				return r_mid;
			}
		val_mid = horner(poly,r_mid);
		// cout<<std::setprecision (17)<<val_A<<" "<<val_B<<" "<<r_A<<" "<<r_B<<" "<<r_mid<<" "<<val_mid <<endl;
		// cout<<std::setprecision (10) <<r_mid<<" "<<val_mid<<endl;
		if(val_mid<precision &&val_mid>-1.0*precision )
		{
			// cout<<"return"<<r_mid<<endl;
			return r_mid;
		}
		if(val_mid*val_A<0)
		{
			r_B=r_mid;
		}
		else if (val_mid*val_B<0)
		{
			r_A=r_mid;
		}

	}
	cout<<val_A<<" "<<val_B<<endl;
}
int gcd(int a,int b)
{
    int m,n;

    m=max(a,b);
    n=min(a,b);
    int temp;
    while(n!=0)
    {
    	temp = n;
    	n = m%n;
    	m = temp;
    }

    return m ;
}
int main()
{
	int T;
	cin>>T;
	for(size_t i =0 ; i< T;i++)
	{
		int M;
		cin>>M;
		std::vector<double> poly(M+1);
		double val_gcd ;
		for(size_t j = 0; j<=M;j++)
		{
			cin>>poly[j];
			
			if(j==1)
			{
				val_gcd = gcd(poly[0],poly[1]);

			}
			else if (j>1)
			{
				val_gcd = gcd(poly[j],val_gcd);
			}

		}
		for(size_t j = 0; j<=M;j++)
		{	
			poly[j] = poly[j]/val_gcd;
			if(j!=0)
				poly[j]=-1.0*poly[j];
		}
		// // cout<<poly[0]<<endl;
		// for(size_t j = 0; j<=M;j++)
		// {	
		// 	cout<<poly[j]<<" ";
		// }
		cout<<"Case #"<<i+1<<": "; 
		cout<<std::setprecision (10) <<find_res(poly)- 1.0<<endl;

	}
}