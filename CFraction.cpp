#include <iostream>

class CFraction{
    int _numerator;
    int _denominator;
public:
    CFraction(int n,int d):_numerator(n),_denominator(d){}
    bool operator<(const CFraction& f){
        if(_denominator * f._denominator > 0)
            return _numerator * f._denominator < _denominator * f._numerator;
        else
            return _numerator * f._denominator > _denominator * f._numerator;    
    }

    bool operator==(const CFraction& f){
        return _numerator * f._denominator == _denominator * f._numerator;
    }

    friend std::ostream& operator<<(std::ostream& os,CFraction f){
        os<<f._numerator<<'/'<<f._denominator;
        return os;
    }
};

template <typename T>
class MaxElement{
public:
    T operator()(T* array_T,int size){
        T tmp = *array_T;
        for(int i = 1;i < size;++i)
            if(tmp < *(array_T + i))
                tmp = *(array_T + i);
        return tmp;        
    }
};


int main(){
    CFraction a_f[4] = {CFraction(8,6),CFraction(-8,4),CFraction(3,2),CFraction(5,6)};
    std::cout<<MaxElement<CFraction>()(a_f,4);

    return 0;
}