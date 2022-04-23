#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// 在此处补充你的代码
    MyNum operator*(const MyNum& n){
        return MyNum((C - '0') * (n.C - '0'));
    }
    operator int(){
        return C;
    }
};

int main() { 
    char m,n;
    cin >> m >>  n;
    MyNum n1(m), n2(n);
    MyNum n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}