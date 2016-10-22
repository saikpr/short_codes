/*input
3
1 1 5 3
1 2 4 5
1 1 2 2
*/
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <cmath>
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

long long int count_l(int A, int B , int K, int N)
{
	if (A==0 && B==0)
	{
		if (K==2)
			return N*(N-1);
		else
			return 0;
	}
	// if (A ==0 )
	// {
	// 	if (B==1)
	// 	{
	// 		return (N)/K;
	// 	}

	// }
	// if (B ==0 )
	// {
	// 	if (A==1)
	// 	{
	// 		return (N)/K;
	// 	}

	// }
	// cout<<"here"<<endl;
	vector<int> remainder_i (K+1,0);
	vector<int> remainder_j (K+1,0); 

	for (long long int i =1;i<=K;i++)
	{
		remainder_i[i] = modpow<long long> (i,A,K);
	}
	for (long long int j =1;j<=K;j++)
	{
		remainder_j[j] = modpow<long long> (j,B,K);
	}
	vector<int> remainder_count(K,0);
	for (long long int i =1;i<=K;i++)
	{
		remainder_count[remainder_i[i]]++;
		remainder_count[remainder_j[i]]++;
	}
	// cout<<"here"<<endl;
	int Val_d =( N-1)/K;
	for (long long int i =0;i<K;i++)
	{
		remainder_count[i]*=(Val_d-1);

	}
	int i =0;
	while(Val_d*K+i<=N)
	{
		remainder_count[(int)modpow<long long> (i,A,K)]++;
		i++;;
	}
	i =0;
	while(Val_d*K+i<=N)
	{
		remainder_count[(int)modpow<long long> (i,B,K)]++;
		i++;
	}
	long long val = 0;
	for(size_t ind = 1;ind<K;ind++)
	{
		val= val + remainder_count[ind]*remainder_count[K-ind];
	}
	val= val + remainder_count[0]*remainder_count[0];

	for(size_t ind =1; ind<=K;ind++)
	{
		if (modpow<long long> (ind,B,K)==modpow<long long> (ind,A,K))
			val = val - 1*(Val_d-1);
	}
	i =0;
	while(Val_d*K+i<=N)
	{
		if (modpow<long long> (i,B,K)==modpow<long long> (i,A,K))
			val = val - 1;
		i++;
	}
	return val;
}


int main()
{
	int T;
	cin>>T;
	int A,B,N,K;
	int min_p =0;
	for(size_t i = 0 ; i<T;i++)
	{

		
		cin>>A>>B>>N>>K;
		// min_p = min(L,R);
		// string st;
		// for(size_t j =0 ; j <min_p; j++)
		// {
		// 	st = st+string("()");
		// }
		cout<<"Case #"<<i+1<<": "<<count_l( A,  B ,  K,  N)<<endl;



	}
}