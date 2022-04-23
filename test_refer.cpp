#include <iostream>

class A{
public:
    A& foo(){
        std::cout<<"this is foo"<<std::endl;
        return *this;
    }    
};

A& foo();
A a = foo();

int main(){

    a.foo();

    return 0;
}