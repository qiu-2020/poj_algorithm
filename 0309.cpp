#include <iostream>
using namespace std;
int gcd(int x, int y){
	return x%y==0?y:gcd(y,x%y);
}
class Fraction
{
    int num, den;
public:
// 在此处补充你的代码
    Fraction(int n,int d):num(n),den(d){}
    Fraction(int c):num(c),den(1){}
    void operator*=(const Fraction& f){
        num *= f.num;
        den *= f.den;
        int tmp = gcd(num,den);
        if(tmp != 1){
            num /= tmp;
            den /= tmp;
        }
    }
    friend ostream& operator<<(ostream& os,const Fraction& f){
        os<<f.num<<'/'<<f.den;
        return os;
    }
    void operator/=(const Fraction& f){
        num *= f.den;
        den *= f.num;
        int tmp = gcd(num,den);
        if(tmp != 1){
            num /= tmp;
            den /= tmp;
        }
    }

    Fraction operator*(Fraction f){
        int _num = num * f.num,_den = den * f.den;
        int tmp = gcd(_num,_den);
        if(tmp != 1) return Fraction(_num / tmp,_den / tmp);
        else return Fraction(_num,_den);
    }

    Fraction operator/(Fraction f){
        int _num = num * f.den,_den = den * f.num;
        int tmp = gcd(_num,_den);
        if(tmp != 1) return Fraction(_num / tmp,_den / tmp);
        else return Fraction(_num,_den);
    }

    operator float(){
        return float(num) / float(den);
    }
};
 
int main() {
	int a,b,c;
	cin >> a >> b >> c;
    Fraction f(a, b), g(c);
	f *= g;
	cout << f << endl;
	f /= g;
	cout << f << endl;
	f = f * f;
	cout << f << endl;
	f = f / g;
	cout << f << endl;
	cout << (float) f << endl;
    return 0;
}