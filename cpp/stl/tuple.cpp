#include <tuple>
#include <iostream>
#include <string>
#include <utility>

std::tuple<int,int,int> foo() 
            { 
            return std::make_tuple( 1, 2, 3 ); 
            } //returning {1,2,3} 
                                //i.e. an intialiser list is error, while it will work for pair
int main()
{   
    std::tuple <int,int,std::string> p1{1,2,"#43"};
    std::tuple <int,int,std::string> p2 {1,2,"helloworld"};
    
    //compare 2 tuples
    std::cout<<(p1<p2)<<std::endl;
    
    std::cout<<std::get<0>(foo());



    //in get<0> we can't use get<i>
    std::cout<<std::endl<<"Another Way 0 Element :"<<std::get<0>(p1)<<" Second Element :"<<std::get<1>(p1);
     // int i=1;
    // std::cout<<std::endl<<"Tryting to print "<<std::get<i>(p1);
}