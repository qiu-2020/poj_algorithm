#include <iostream>

int main(){
    std::string str;
    while(std::cin.peek() != EOF){
        std::cin>>str;
        std::cout<<str<<std::endl;
    }


    return 0;
}