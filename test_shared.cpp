#include <iostream>
#include <memory>

void fun(std::shared_ptr<int> s_p){
    return;
}

int main(){
    std::shared_ptr<int> s_p1(new int(42));
    auto ptr = new int();
    // fun(std::shared_ptr<int>(s_p1.get()));
    // fun(ptr);
    return 0;
}