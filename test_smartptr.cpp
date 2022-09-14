#include <iostream>
#include <memory>

int main(){
    std::shared_ptr<std::string> p1 = std::make_shared<std::string>("42good");
    
    std::cout<<*p1<<std::endl;

    return 0;
}