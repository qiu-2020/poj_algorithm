#include <iostream>

int count_factor(int n,int m){
    int count = 0;
    for(int i = m;i <= n;++i){
        if(n % i != 0) continue;
        if(n == i) count++;
        if(n / i >= i){
            count += count_factor(n / i,i);
        }     
    }
    return count;
}

int count_factor1(int n,int m){
    int count = 0;
    if(m == n){
        count = 1;
        return count;
    }
    if(n % m != 0) return count + count_factor1(n,m + 1);
    if(n / m >= m) return count + count_factor1(n / m,m);
}

int main(){
    int n,x;
    std::cin>>n;
    for(int i = 0;i <n;++i){
        std::cin>>x;
        std::cout<<count_factor1(x,2)<<std::endl;
    }    
    return 0;
}

//8 2*4  2*2*2
// 16 2*8 2*2*4 2*2*2*2 4*4
//10 2*5
//12 2*6 2*2*3 3*4