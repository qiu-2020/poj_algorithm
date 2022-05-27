#include <iostream>
using namespace std;
// 在此处补充你的代码

class A{
    friend class B;
    friend class C;
    int value;
public:
    A(int v):value(v){}
    virtual int get_value(){
        return value;
    }
    friend A operator+(const A& a,const A& b){
        return A(a.value + b.value);
    }
    // operator A(){
    //     return 
    // }
    A& operator+(A* pa){
        value += pa->value;
        return *this;
    }
    A* operator ->(){
        return this;
    }
};

class B : public A{
    
public:
    B(int v):A(v){}
    // virtual int get_value(){
    //     return A::value;
    // }

};
class C : public A{
public:    
    C(int v):A(v){}
    // virtual int get_value(){
    //     return A::value;
    // }

};

int main() {
    int t;
    cin >> t;
    while (t --){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        //1,2,3
        A a(aa);
        //1
        B b(bb);
        //2
        C c(cc);
        //3
        A* x = &a;
        //
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        // cout<<(*(x) + y)->get_value()<<endl;
        // cout<<(*(x) + y + z)<<endl;
        cout << ((*x) + y + z)->get_value() << endl;
        // A->getvalue() : (p.operator->())->get_value()   
        // A + A* + A* 
        // cout<< x->()<<std::endl;
    }
    return 0;
}