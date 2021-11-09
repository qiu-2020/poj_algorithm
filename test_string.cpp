#include <iostream>

int main(){

    std::string s;
    while(true){
        if(std::cin.peek() == '1')
            std::cout<<(std::cin.get() - '0');
        else if(std::cin.peek() == ' ')
            std::cin.get();
        else if(std::cin.peek() == '\n')
            break;
    }
    return 0;
}   