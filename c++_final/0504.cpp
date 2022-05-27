#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
// 在此处补充你的代码
    Fraction():p(0),q(1){}
    Fraction(int p_):p(p_),q(1){}
    Fraction(int p_,int q_):p(p_),q(q_){}
    Fraction operator*(Fraction& f){
        int ans_p,ans_q;
        int tmp = gcd(p * f.p,q * f.q);
        if(tmp == 1){
            ans_p = p * f.p;
            ans_q = q * f.q;
        }
        else{
            ans_p = (p * f.p) / tmp;
            ans_q = (q * f.q) / tmp;
        }
        return Fraction(ans_p,ans_q);
    }
    Fraction operator*(int& n){
        int tmp = gcd(q,n),ans_p = p,ans_q = q;
        if(tmp == 1) ans_p = n * p;
        else ans_q = q / n;
        return Fraction(ans_p,ans_q);
    }

    friend Fraction operator*(const Fraction& a,const Fraction& b){
        // Fraction ret;
        // ret.p = a.p * b.p;
        // ret.q = a.q * b.q;
        int d = gcd(a.p * b.p,a.q * b.q);
        // ret.p /= d;
        // ret.q /= d;
        return Fraction(a.p * b.p / d,a.q * b.q / d);    
    }

    friend istream& operator>>(istream& is,Fraction& frac){
        int t_1,t_2;
        is>>t_1>>t_2;
        int tmp = gcd(t_1,t_2);
        if(tmp == 1){
            frac.p = t_1;
            frac.q = t_2;
        }
        else{
            frac.p = t_1 / tmp;
            frac.q = t_2 / tmp;
        }    
        return is;
    }
    friend ostream& operator<<(ostream& os,Fraction& frac){
        //&类型报错
        if(frac.q == 1) os<<frac.p;
        else{
            os<<frac.p<<'/'<<frac.q;
        }
        return os;
    }

};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        Fraction c = a* b;
        // cout << a << " * " << b << " = " << c << endl;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
        // cout << a << " * " << b << " = " << endl;
        // cout << "2 * " << a <<  two * a << endl;
        // cout << b << b * 3 << endl;
    }
    return 0;
}