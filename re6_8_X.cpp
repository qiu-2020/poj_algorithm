#include <iostream>

int number_of_bits(int n){
    if(n < 2) return 1;
    else{
        return 1 + number_of_bits(n >> 1);
    }
}
int multiply_karatsuba(int x,int y){
    if(x == 0 && y == 0) return 0;
    else if(x == 1) return y;
    else if(y == 1) return x;
    else{
        int x_bits = number_of_bits(x);
        int y_bits = number_of_bits(y);
        int shift = std::min(x_bits / 2,y_bits / 2);
        int a1 = x >> shift,b1 = x - a1 << shift;
        int a2 = y >> shift,b2 = y - a2 << shift;
        
    }
}



int main(){




    return 0;
}