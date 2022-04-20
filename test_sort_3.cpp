#include <iostream>
#include <algorithm>
#include <functional>

class A{
private:
    int _a;
public:
    A(int a):_a(a){}
    bool operator>(const A& a){
        return _a > a._a;
    }
    friend bool operator>(const A& a,const A& b){
        return a._a > b._a;
    }

    friend std::ostream& operator<<(std::ostream& os,const A& a){
        os<<a._a;
        return os;
    }    
};

void PrintA(A* ptr_a,int size){
    for(int i = 1;i < size;++i){
        std::cout<<ptr_a[i]<<' ';
    }
    std::cout<<std::endl;
}

int main(){
    A arr_a[4]{1,-3,9,100};
    std::sort(arr_a,arr_a + 4,std::greater<A>());
    PrintA(arr_a,4);
    std::cout<<"hello"<<std::endl;

    return 0;
}