#include <iostream>
#include <set>

class A{
private:
    int _a;
    class B{
    friend class A;
    private:
        int _b;
    public:
        bool operator<(const B&) const;
        B(int b):_b(b){} 
    };
    B _B_object;
    std::set<B> _set_B;   
public:
    A(int a):_a(a),_B_object(a){}
    void add_set(const int& a){
        B tmp(a);
        _set_B.emplace(tmp);
    }    
};
bool A::B::operator<(const B& b) const{
    return _b < b._b;
}            

int main(){
    A a(99);
    for(int i = 50;i >= 0;--i){
        a.add_set(i);
    }
    std::cout<<"good"<<std::endl;
    return 0;
}