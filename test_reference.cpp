#include <iostream>

// Int func(int a){
//     return Int(a);
// }
// class Int{
// private:
//     int v;
// public:
//     Int(int x):v(x){}
// };

int func(int x){
    return x + 99;
}
int func2(int& x){
    return x + 88;
}

int main(){
    int x = 999;
    // Int& x = func(x);
    // int b = func2(func(x));


    return 0;
}