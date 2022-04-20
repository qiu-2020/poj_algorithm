#include <iostream>


int main(){
    std::pair<std::string,int> p1;
    std::cout<<p1.first<<' '<<p1.second<<std::endl;
    std::pair<int,int> a = std::make_pair<int,int>(99,99);
    std::cout<<a.first<<' '<<a.second<<std::endl;

    return 0;
}