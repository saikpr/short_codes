#include<iostream>
#include<memory>
using namespace std;

int main ()
{
	string s1;
	cout<<"Enter the String:";
	cin>>s1;
	shared_ptr<string> ptr1=make_shared<string>(s1);
	shared_ptr<string> ptr2;
	ptr2=ptr1;
	cout<<"Use Count: "<<ptr1.use_count()<<endl;
	ptr2=nullptr;
	cout<<"Use Count: "<<ptr1.use_count()<<endl;
	auto ptr3=ptr1;
	cout<<"Use Count: "<<ptr1.use_count()<<endl;	

	string *s2= new string;
	cout<<"Enter Second String:";
	cin>>*s2;
	cout<<*s2;
	unique_ptr<string> ptr4(s1);
	cout<< *ptr4;
}