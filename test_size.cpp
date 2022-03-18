#include <iostream>

class A{
public:
    int a;
    float b;
};
A a[100];

int main(){
    a[99].a = 19920703;
    std::cout<<sizeof(a) / sizeof(a[0])<<std::endl;
    std::cout<<(a + sizeof(a) / sizeof(a[0]) - 1) -> a<<std::endl;
    return 0;
}