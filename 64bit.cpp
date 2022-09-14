#include <iostream>

long long mul(long long a,long long b,long long p){
    if(p == 1) return 0;
    long long ans = 0;
    for(;b;b >>= 1){
        if(b & 0x1) ans += a % p;
        a = a * 2; 
    }
}

int main(){


    return 0;
}