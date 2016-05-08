#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX_VAL 2500
using namespace std;

int compare_count_nnary (int arr[],int min, int max, int search_key,int n=2)
{
	int len= max -min +1;

	int i=0,j=0;
	if (len<=n)
	{
		while(j<len)
		{
			if(arr[j+min]==search_key)
				return j+1;
			j++;
		}
	}
	else{
	while (j<n)
	{	j++;
		//cout<<"J: "<<j<<" Midn:"<<min + (int)(((float)len)*j/n)-1<<endl;
	
		
		if (arr[min + (int)(((float)len)*j/n)-1]==search_key)
			{return (2*j-1);}
		if (arr[min + (int)(((float)len)*j/n)-1]>search_key)
			{return 2*j+compare_count_nnary(arr,min + (int)(((float)len)*(j-1)/n),min + (int)(((float)len)*j/n)-1,search_key,n);}
	}
	}
	if (min==max)
	{
		cout<<"Error min: "<<min<<" max: "<<max<<" search_key: "<< search_key<<" n: "<<n<<" : ";
	}
	cout<<"Error min: "<<min<<" max: "<<max<<" search_key: "<< search_key<<" n: "<<n<<" : "<<endl;
}


int main ()
{
	int arr[MAX_VAL];
	int i=0;
	for(i=0;i<MAX_VAL;i++)
		arr[i]=i;
	int var_n,var_key,var_n_sum=0;
	int var_max=11;
	int var_n2_sum=0;
	for (;var_max<MAX_VAL;var_max++)
	{	//cout<<var_max<<endl;
		vector<pair<int,int>> v;
		for (var_n=2;var_n<20;var_n++)
		{	var_n_sum=0;

			for (var_key=0;var_key<var_max;var_key++)
			{
				var_n_sum+=compare_count_nnary(arr,0,var_max-1,var_key,var_n);
			}
			if(var_n==2)
				{var_n2_sum=var_n_sum;}
			v.push_back(make_pair(var_n_sum,var_n));
			//cout<<"var_n :"<<var_n<<" var_n_sum :"<<var_n_sum<<endl;	
		}
		auto k=min_element(v.begin(),v.end());
		cout<<"for "<<var_max<<" : "<<(*k).second<<" is the best, with error :"<<((float)(*k).first-var_n2_sum)*-100/(*k).first<<endl;
		cout<<(float)(*k).first<<" : "<<var_n2_sum<<endl;
	}
	//cout<<compare_count_nnary(arr,0,MAX_VAL-1,1000,2);
}