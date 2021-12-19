#include <iostream>

const int MAX = 100000;
bool isprime[MAX];

void prime(int n){//筛出前n的素数
    for(int i = 0;i <= n;++i)
        isprime[i] = true;
    isprime[0] = false; isprime[1] = false;
    for(int i = 2;i <= n;++i){
        if(isprime[i])
            for(int j = i * 2;j <= n;j += i)
                isprime[j] = false;
    }    
}

int main(){
    prime(21610);

    std::cout<<isprime[21609]<<std::endl;

    return 0;
}