/*input
3
1 2 3
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
using namespace std;
const size_t BITSIZE = 64;
typedef unsigned int uint;
typedef bitset<BITSIZE> bit_t;

//BASE TRIE CLASS
class baseTrie
{
    public:
        virtual void add(string ) =0;
        virtual bool check(string )=0;
};
//BIT TRIE NODE
struct bitTrieNode {
    int val; 
    vector<bitTrieNode*> leaf; //Assumption 2 bit
    bitTrieNode(int v):leaf({NULL,NULL})
    {
        val =v;
    }
};
//BIT TRIE
class bitTrie:public baseTrie
{
    private:
        bitTrieNode *root ;//TODO assert length of each string uqery
    public:
        bitTrie()
        {
            root = new bitTrieNode(-1);
        }
        void add(string str); //Adds BIT string to Trie
        bool check(string str); // Checks if valid
        uint getMaxDiff(string str); // Gets Max Diff for XOR
};

void bitTrie::add(string str)
{
    assert(str.size()==BITSIZE);
    bitTrieNode *temp = root;
    
    for(size_t i = 0 ; i < str.size();i++)
    {
        if (temp->leaf[str[i]-'0']==NULL)
        {
            temp->leaf[str[i]-'0'] = new bitTrieNode(str[i]-'0');
        }
        temp = temp->leaf[str[i]-'0'];
    }
    return;
    
}

bool bitTrie::check(string str)
{
    assert(str.size()==BITSIZE);
    bitTrieNode *temp = root;
    
    for(size_t i = 0 ; i < str.size();i++)
    {
        if (temp->leaf[str[i]-'0']==NULL)
        {
            return false;
        }
        temp = temp->leaf[str[i]-'0'];
    }

    for(size_t i = 0 ; i < temp->leaf.size();i++)
    {
        if (temp->leaf[i]!=NULL)
            return false;
    }
    return true;
}
uint bitTrie::getMaxDiff(string str)
{
    assert(str.size()==BITSIZE);
    bitTrieNode *temp = root;
    string st;
    for(size_t i = 0 ; i < str.size();i++)
    {
        int val = (str[i]-'0')^1;
        if (temp->leaf[val]!=NULL)
        {
            st.push_back(val+'0');
            temp = temp->leaf[val];
        }
        else
        {
            val = val^1;
            st.push_back(val+'0');
            temp = temp->leaf[val];
            
        }
        
    }
    // cout<<"MAX"<<st<<endl;
    return bit_t(st).to_ulong();
    
}


int main() {
    int n;
    cin>>n;
    
    vector<uint> vec(n);
    for(size_t i = 0 ; i < n ; i ++)
    {
        cin>>vec[i];
    }
    vector<uint> pre(n,0),suf(n,0); //prefix and suffix xors
    pre[0]= vec[0];
    suf[n-1] = vec[n-1];
    
    for(size_t i = 1 ; i < n ; i ++)
    {
        pre[i] = vec[i]^pre[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        suf[i] = vec[i]^suf[i+1];
    }
    
    bitTrie  myTrie;
    myTrie.add(bit_t(0).to_string());
    uint max_xor = 0;
    /*
    Algo 
    1) get the best possible prefix from myTrie
    2) test against global max_xor
    3) add the prefix xor till this position to Trie
    */
    for(int i =0; i < n;i++)
    {
        uint temp_left= myTrie.getMaxDiff(bit_t(suf[i]).to_string());
        max_xor = max(max_xor,temp_left^suf[i]);
        myTrie.add(bit_t(pre[i]).to_string());

    }
    cout<< max_xor;
    
    return 0;
}