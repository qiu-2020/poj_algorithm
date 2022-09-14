#include <iostream>
#include <cstdlib>

class integer{
private:
    int _i;
public:
    integer():_i(rand()){}
    integer(int i):_i(i){}
    int operator+(integer& a){
        return _i + a._i;
    }
    int operator-(integer& a){
        return _i - a._i;
    }
    int operator*(integer& a){
        return _i * a._i;
    }
};

int main(){
    int a,b;
    std::cin>>a>>b;
    integer a_int(a),b_int(b);
    std::cout<<a_int + b_int<<' '<< a_int - b_int <<' '<<a_int * b_int<<std::endl;


    return 0;
}