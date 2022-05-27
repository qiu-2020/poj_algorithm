#include <cstdio>
#include <iostream>
using namespace std;

class f {
// 在此处补充你的代码
private:
    int _a,_b;
public:
    f(int a):_a(a){}
    f(int a,int b):_a(a),_b(b){}
    int operator()(const int& b){
        return b - _a;
    }
    // int operator()(void){
    //     return _a * _b;
    // }    
    friend ostream& operator<<(ostream& os,const f& f_){
        os<<f_._a * f_._b;
        return os;
    }

};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}