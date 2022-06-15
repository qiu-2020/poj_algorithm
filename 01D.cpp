#include <iostream>

int frac_int(int n,int m){
    int ans = 0;
    if(n == 1) return 1;
    else{
        for(int i = 2;i <= m;++i){
            if(n % i == 0)
                ans += frac_int(n / i,i);
        }
    }
    return ans;
}

int main(){
    int N,n;
    std::cin>>N;        
    for(int i = 0;i < N;++i){
        std::cin>>n;
        std::cout<<frac_int(n,n)<<std::endl;
    }
    return 0;
}