#include <iostream> 

int ans[15][15];
int m,n;
int apple(int n,int m){//n个苹果放m个盘子
    if(m > n) return apple(n,n);
    if(m == 1) return 1;
    if(n == 1) return 1;
    return apple(n - m,m) + apple(n,m - 1);
}

void apple_dp(void){
    // for(int i = 0;i <= n;++i){
    //     for(int j = 1;j <= m;++j){
    //         if(i == 1) ans[i][j] = 1;
    //         if(j == 1) ans[i][j] = 1;
    //         if(i == 0) ans[i][j] = 1;
    //         if(j > i) ans[i][j] = ans[i][i];
    //         else ans[i][j] = ans[i - j][j] + ans[i][j - 1];
    //     }
    // }
}

int main(){
    int t = 0;
    std::cin>>t;
    for(int i = 0;i < t;++i){
        std::cin>>n>>m;
        apple_dp();
        std::cout<<ans[n][m]<<std::endl;
    }

    return 0;
}