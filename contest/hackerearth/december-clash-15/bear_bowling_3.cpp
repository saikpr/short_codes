#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
template <typename T>
T InverseEuler(T val_n, T modulus)
{
    return modpow<T>(val_n,modulus-2,modulus);
}

template <typename T>
T nCrmod(T val_n, T val_r, T modulus)
{
    vector<T> f(val_n + 1,1);
    for (T i=2; i<=val_n;i++)
        f[i]= (f[i-1]*i) % modulus;
    return (f[val_n]*((InverseEuler(f[val_r], modulus) * InverseEuler(f[val_n-val_r], modulus)) % modulus)) % modulus;
}

int main()
{
	//cout<<" 2^20 mod 50"<< modpow<long long>(2,4,50);
	//cout<<"5c4 mod 30"<<nCrmod<long long>(5,4,30);
	long long n;
	long long i,j,k;
	long long sum_val=0,temp_val;
	long long mod_val=1000000007;
	cin>>n;
	const long long len=n;
	std::vector<long long int> val_A(n);
	std::vector<long long int> pow2_mod_vec(n+1);
	pow2_mod_vec[0]=1;
	cin>>val_A[0];
	for (i =1; i<n;i++ )
	{
		cin>>val_A[i];
		pow2_mod_vec[i]=(pow2_mod_vec[i-1]*2)%mod_val;


	}

	for (j=n-1;j>=0;j--)
	{	i=(n-1)-j;
		temp_val=0;
		for (k=0;k<=i;k++)
		{
			temp_val=(temp_val+nCrmod<long long>(i,k,mod_val)*(k+1))%mod_val;
		}
		temp_val = (pow2_mod_vec[j]*temp_val)%mod_val;
		sum_val = (sum_val+(temp_val*val_A[i])%mod_val)%mod_val;
	}
	cout<<sum_val;
}