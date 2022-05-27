#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
// 在此处补充你的代码
    Fraction(){
        p = 0;
        q = 1;
    }
    Fraction(int x):p(x),q(1){}
    friend istream& operator>>(istream& is,string& s){
        is>>s;
        int i = s.find(' ')

    }
};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}