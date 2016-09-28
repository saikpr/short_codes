/*input
barfoobarfoothefoobarfooman
2
foo
bar
*/#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

const unsigned int mod=1000000007;
const unsigned int multiplier = 31;
unsigned int val_supermultiplier = 1;

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

unsigned int update_hash(unsigned int prev_hash, char add_elem, char remove_elem)
{
	long long hash_value = prev_hash;

	hash_value = hash_value - remove_elem + mod*(long long)multiplier;
	hash_value/=multiplier;
	hash_value %= mod;
	hash_value +=(add_elem*val_supermultiplier);
	hash_value %=mod;

	return (unsigned int)hash_value;
}

vector< int> substring_concatenation(string &S, vector<string> &words)
{
	unsigned int n = S.size();
	unsigned int m = words.size();
	assert(n>0&&m>0);
	unsigned int k = words[0].size();
	assert(k*m<=n);
	// cout<<n<<" "<<m<<" "<<k<<endl;
	vector<int> to_return;
	unsigned int first_hash=0;
	val_supermultiplier = 1;
	for(size_t i = 0 ; i < k ; i++)
	{
		// first_hash = (long long)first_hash;
		
		first_hash += (S[i]*modpow<unsigned int> (multiplier,i,mod));
		first_hash %=mod;
		// val_supermultiplier = (val_supermultiplier * (long long)multiplier)%mod;
		
	}
	val_supermultiplier = modpow<unsigned int> (multiplier,k-1,mod);
	assert(n-k*m+1>0);
	vector<unsigned int> hashes(n-k+1);
	hashes[0] = first_hash;
	for(size_t i = 1 ; i <n-k+1;i++)
	{
		
		hashes[i] = update_hash(hashes[i-1],S[i+k-1],S[i-1]);
		// cout<<i<<" "<<S[i+k-1]<<" "<<S[i-1]<<" "<<hashes[i]<<endl;
	}
	unsigned int overall_hash = 0 ;
	for(size_t j =0 ; j<m;j++)
	{
		unsigned int this_hash = 0;
		for(size_t i = 0 ; i < k ; i++)
		{
			// first_hash = (long long)first_hash;
			
			this_hash += (words[j][i]*modpow<unsigned int> (multiplier,i,mod));
			this_hash %=mod;
			// val_supermultiplier = (val_supermultiplier * (long long)multiplier)%mod;
			
		}
		// cout<<words[j]<< " "<<this_hash<<endl;
		overall_hash = overall_hash^this_hash;
	}
	// cout<<overall_hash<<endl;
	
	// for(size_t i = 0 ; i <hashes.size() ; i++)
	// {
	// 	cout<<hashes[i]<<" ";
	// }
	// cout<<endl;
	for(size_t i = 0 ; i <k ; i++)
	{
		unsigned hash_to_check = 0;
		size_t count = 0 ;
		while(count<m && count*k+i<hashes.size())
		{
			// cout<<i+count*k<<endl;
			hash_to_check = hash_to_check^hashes[i+count*k];
			count++;

		}
		// count--;
		if (hash_to_check == overall_hash)
		{
			to_return.push_back(i+(count-m)*k);
		}
		// cout<<hash_to_check<<endl;
		while(count*k+i<hashes.size())
		{
			// cout<<i+count*k<<endl;
			hash_to_check = hash_to_check^hashes[i+(count-m)*k];
			hash_to_check = hash_to_check^hashes[i+count*k];
			count++;
			if (hash_to_check == overall_hash)
			{
				to_return.push_back(i+(count-m)*k);
			}
		}


	}
	sort(to_return.begin(), to_return.end());
	return to_return;
}

int main()
{
	string S;
	cin>>S;
	unsigned int m ;
	cin>>m;
	std::vector<string> words(m);
	for(size_t i = 0 ; i < m ; i ++)
	{
		cin>>words[i];
	}
	vector< int> vec = substring_concatenation(S,words);
	for(size_t i = 0 ; i < vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
}