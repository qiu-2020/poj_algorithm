#include <iostream>

class A{
private:
    int x,y;
public:
    A():x(0),y(0){}
    A(int x_,int y_):x(x_),y(y_){}    
};

int main(){
    A* ptr = new A [10];
    for(int i = 0;i < 10;++i){
        // (ptr + i) = new 
    }


    return 0;
}