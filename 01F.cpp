#include <iostream>

int g(int);
int f(int);

// int cover(int n){
//     if(n % 2 == 1) return 0;
//     else return f(n - 2) + 2 * g(n - 1);
// }

int f(int n){
    if(n % 2 == 1) return 0;
    if(n == 0) return 1;
    else if(n == 1) return 0;
    else return f(n - 2) + 2 * g(n - 1) + g(n);
}

int g(int n){
    if((n * 3 - 1) % 2 == 1) return 0;
    if(n == 1) return 1;
    else if(n == 0) return 0;
    else return f(n - 1) + g(n - 2);
}

int ans_f[35],ans_g[35];

// void cover_dp(void){
//     ans_f[0] = 1; ans_f[1] = 0;
//     ans_g[0] = 0; ans_g[1] = 1; ans_g[2] = 0;
//     for(int i = 2;i <= 30;++i){
//         if(i % 2 == 1) ans_f[i] = 0;
//         ans_f[i] = ans_f[i - 2] + 2 * ans_g[i - 1];
//         if(i >= 3)
//             ans_g[i] = ans_f[i - 1] + ans_g[i - 3]; 
//     }
// }


int main(){
    int n;
    while(std::cin>>n && n != -1){
        // cover_dp
        std::cout<<f(n)<<std::endl;
    }

    return 0;
}