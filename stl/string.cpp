#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string s1("This is a very large large string, and i am now trying to work with it in C++, and just so you know which just might be a little messy language");

	// string s2;
	// cout<<"Enter A new String (escaped by \\n)"<<endl;
	// getline(cin,s2,'\n');
	// cout<<"Size of the the String you entered :"<<s2.size()<<endl;
	cout<<"Size of string s1 :"<<s1.size()<<endl;
	cout<<"printing part of string s1 from 10 postition printing 5 characters : "<<s1.substr(0,9)<<":::its size:::"<<(s1.substr(0,9)).size()<<endl;
	auto k=s1.find("and",0);
	cout<<"Finding \"and\" in string s1"<<k<<endl;
	cout<<"Finding Second occurance in string s1 :"<<s1.find("and",k+1)<<endl;
	cout<<"Finding last occurance in string s1 :"<<s1.rfind("and")<<endl;

	string s3("abcdefghi");
	cout<<"Lets take a new string \""<<s3<<"\"" <<endl;
	cout<<"I have erased 2 character from 4 postition String Now:"<<s3.erase(4,2)<<endl;
	cout<<"Okay i will now add it again "<<s3.insert(4,"ef")<<endl;
	reverse(s3.begin(),s3.end());
	cout<<"reverse :"<<s3;
}