#include <iostream>

class A{
public:
    int _value;
    A(int v):_value(v){}
    friend A* operator+(A* pa,A* pb){
        
    }
};


int main(){
    A* pa = new A(99);


    return 0;
}