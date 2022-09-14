#include <iostream>
using namespace std;
// 在此处补充你的代码
class B;
class C;

class A{
private:
    int _a;
public:
    A(int a):_a(a){}
    virtual int get_value(){
        return _a;
    }
    A operator+(A* ptr_b){
        return A(_a + ptr_b->get_value());
    }   
    // C* operator+(C* ptr_c){
    //     return new C(_a + ptr_c->get_value());
    // }  
    A* operator->(){
        return this;
    }  
};

class B : public A{
private:
    int _b;
public:
    B(int b):A(0),_b(b){}
    virtual int get_value(){
        return _b;
    }     
};

class C : public A{
private:
    int _c;
public:
    C(int c):A(0),_c(c){}
    virtual int get_value(){
        return _c;
    }        
};


int main() {
    int t;
    cin >> t;
    while (t --){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        A a(aa);
        B b(bb);
        C c(cc);
        A* x = &a;
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        cout << ((*x) + y + z)->get_value() << endl;
    }
    return 0;
}