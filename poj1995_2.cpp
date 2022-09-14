#include <iostream>

int power(int a,int b,int p){
    if(p == 1) return 0;
    int ans = 1;
    for(;b;b >>= 1){
        if(b & 0x1) ans = (long long) ans * a % p;
        a = a * a % p;
    }
    return ans % p;
}

int main(){
    int Z,M,H,a,b,ans;
    std::cin>>Z;
    for(int i = 0;i < Z;++i){
        std::cin>>M>>H;
        ans = 0;
        for(int j = 0;j < H;++j){
            std::cin>>a>>b;
            ans += power(a,b,M);
            ans %= M;
        }
        std::cout<<ans<<std::endl;
    }


    return 0;
}