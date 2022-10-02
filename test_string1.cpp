#include <iostream>
#include <string>

int main(){
    std::string str("a");
    std::cout<<str<<std::endl;
    str = str.substr(1);
    std::cout<<str<<std::endl;
    std::cout<<"helloworld"<<std::endl;
    return 0;
}