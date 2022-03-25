#include <iostream>

int power(int a,int b,int m){
    int ans = 1 % m;
    for(;b != 0;b >>= 1){
        if(b & 0x1 == 1) ans = (long long)ans * a % m;
        a = (long long)a * a % m; 
    }
    return ans % m;
}

int main(){
    int Z,M,H,ans,a,b,Ans = 0;
    std::cin>>Z;
    for(int i = 0;i < Z;++i){
        std::cin>>M>>H;
        Ans = 0;
        for(int j = 0;j < H;++j){
            std::cin>>a>>b;// 计算 a ^ b
            Ans += power(a,b,M);
            Ans %= M;
        }
        std::cout<< Ans <<std::endl;
    }

    return 0;
}