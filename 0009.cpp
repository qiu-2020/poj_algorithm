#include <iostream>
using namespace std;
// 在此处补充你的代码

class Complex{
private:
    int _real,_imag;
public:
    Complex(int r,int i):_real(r),_imag(i){}
    Complex():_real(0),_imag(0){}
    Complex(const string& str){
        int r = str[str.find('+') - 1] - '0';
        int i = str[str.find('+') + 1] - '0';
        _real = r;
        _imag = i;
    }  
    Complex(int r):_real(r){
        _imag = 0;
    }
    Complex(const Complex& c){
        _real = c._real;
        _imag = c._imag;
    }
    friend ostream& operator<<(ostream& os,const Complex& c){
        if(c._real == 0 && c._imag == 0)
            os<<0;
        else{
            if(c._real != 0){
                os<<c._real;
                if(c._imag != 0){
                    if(c._imag < 0)
                        os<<c._imag<<'i'; 
                    else os<<'+'<<c._imag<<'i';    
                }       
            }    
            else{
                if(c._imag != 0)
                    os<<c._imag<<'i';
                else os<<0;        
            }
        }    
        return os;
    }
    Complex operator+(const Complex& c){
        return Complex(_real + c._real,_imag + c._imag);
    }
    Complex operator-(const Complex& c){
        return Complex(_real - c._real,_imag - c._imag);
    }
    Complex operator*(const Complex& c){
        int ans_r,ans_i;
        ans_r =  _real * c._real - (_imag * c._imag);
        ans_i =  (_real * c._imag) + (_imag * c._real);
        return Complex(ans_r,ans_i);
    }
    Complex& operator+=(const Complex& c){
        _real += c._real;
        _imag += c._imag;
        return *this;
    }
    Complex& operator-=(const Complex& c){
        _real -= c._real;
        _imag -= c._imag;
        return *this;
    }
    Complex& operator*=(const Complex& c){
        // _real *= c._real;
        // _imag = -(_imag * c._imag);
        // return *this;
        int tmp_r_1 = _real,tmp_i_1 = _imag;
        int tmp_r_2 = c._real,tmp_i_2 = c._imag;
        _real =  tmp_r_1 * tmp_r_2 - (tmp_i_1 * tmp_i_2);
        _imag =  tmp_i_2 * tmp_r_1 + tmp_i_1 * tmp_r_2;
        return *this;
    }
};

int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
    // -12 + 2 i
	cout << c2 << endl;
	c2 -= -12;
    // 0 + 2 i
	cout << c2 << endl;
	c3 *= c3;
    // 3 + 2i
    // 3 + 2i
	cout << c3 << endl;
	return 0;
}