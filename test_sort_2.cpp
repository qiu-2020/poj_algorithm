#include <iostream>
#include <algorithm>

class A{
private:
    int _a;
public:
    A(int a):_a(a){}
    int get_A() const{ return _a;}        
};

void PrintA(A* arr_A,int size){
    for(int i = 0;i < size;++i)
        std::cout<<(arr_A + i)->get_A()<<' ';
    std::cout<<std::endl;    
}

template<typename T>
class less{
public:
    bool operator()(const T& x1,const T& x2){
        return x1.get_A() % 10 < x2.get_A() % 10;
    }    
};

int main(){
    A arr_A[7]{1,9,22,23,55213,3123,5462};
    std::sort(arr_A,arr_A + 7,less<A>());
    PrintA(arr_A,7);
    return 0;
}