#include<iostream>
#include<limits>

int main()
{
	std::cout<<"Using numeric_limits:"<<std::endl;
	std::cout<<"Max of Int :"<<std::numeric_limits<int>::max() <<std::endl;
	std::cout<<"Min of Int :"<<std::numeric_limits<int>::min() <<std::endl;
	std::cout<<"Number of digits in Int :"<<std::numeric_limits<int>::digits <<std::endl;
	std::cout<<"Number of digits base 10 in Int :"<<std::numeric_limits<int>::digits10 <<std::endl;
	std::cout<<"Min of unsigned Int :"<<std::numeric_limits<unsigned int>::min() <<std::endl;
	std::cout<<"Miaxof unsigned Int :"<<std::numeric_limits<unsigned int>::max() <<std::endl;



	std::cout<<"Max of float :"<<std::numeric_limits<float>::max() <<std::endl;
	std::cout<<"Min of float :"<<std::numeric_limits<float>::min() <<std::endl;
	std::cout<<"Number of digits in float :"<<std::numeric_limits<float>::digits <<std::endl;
	std::cout<<"Number of digits base 10 in float :"<<std::numeric_limits<float>::digits10 <<std::endl;

}