//Auxilary Functions
#include <iostream>
#include <algorithm> //initialiser list in algorithm header file
bool ptr_compare(int *a,int *b)// function that compares two pointers by comparing the values to which they point 


{
	return *a<*b;
}
bool int_less (int a, int b) { return a <b; }
int main ()
{	
	//simple comparision
	int a=12,b=23,c=24,d=345345,e=1;
	int *p1=&a,*p2=&b,*p3=&c,*p4=&d,*p5=&e;
	//swapping a and b
	std::swap(a,b);
	std::cout<<"Value of a:"<<*p1<<" b:"<<b<<std::endl;

	//Comparision
	std::cout<<"Simple comparision :"<<std::min(a,b)<<std::endl;
	std::cout<<"Simple comparision initialiser list:"<<std::max({a,b,c,d,e})<<std::endl;
	auto extreme_int =std::minmax ({a,b,c,d,e});
	std::cout<<"Finding Extremes "<<extreme_int.first<<" "<<extreme_int.second<<std::endl;
	std::cout<<"Pointer comparision (Direct Address):"<<std::min(p1,p2)<<std::endl;
	std::cout<<"Pointer comparision (Pointer Values):"<<std::min(*p1,*p2)<<std::endl;
	std::cout<<"Pointer comparision (Pointer Values)initialiser list:"<<std::min({*p1,*p2,*p3,*p4,*p5})<<std::endl;
	std::cout<<"Pointer comparision (On pointer using external comaprison operator, returns a pointer):"<<std::min(p1,p2,ptr_compare)<<std::endl;
	std::cout<<"Pointer comparision (On pointer using external comaprison operator, returns a pointer):"<<std::min({p1,p2,p3,p4,p5},ptr_compare)<<std::endl;
	std::pair<int*,int*> extremes = std::minmax ({p1,p2,p3,p4,p5}, ptr_compare); 
	std::cout<<"Finding Extremes on Pointers: "<<*(extremes.first)<<" "<<*(extremes.second)<<std::endl;

	//auto also works
	auto ext = std::minmax ({p1,p2,p3,p4,p5}, ptr_compare); 
	std::cout<<"Finding Extremes on Pointers: "<<*(ext.first)<<" "<<*(ext.second);
	//std::cout<<std::min({1,2},int_less);
}
