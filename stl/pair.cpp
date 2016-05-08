#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair <int,std::string> p1 ={1,"helloworld"};
    std::pair <int,std::string> p2(1,"ielloworld");
    std::cout<<"Pair First :"<<p1.first<<" Pair Second :"<<p1.second;
    std::cout<<(p1<p2);
    std::cout<<std::endl<<"Another Way 0 Element :"<<std::get<0>(p1)<<" Second Element :"<<std::get<1>(p1);
    //below is illegal 
    // int i=1;
    // std::cout<<std::endl<<"Tryting to print "<<std::get<i>(p1);
}