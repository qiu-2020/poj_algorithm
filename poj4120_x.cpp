#include <iostream>
#include <cstring>

const int MAX = 210;
int x,n;
int a[MAX];
// bool ans[MAX];
bool ans_dp[10010][MAX];
bool flag[MAX];
//memset(flag,0,sizeof(flag));    

void coin(int index){ //验证去掉index可不可以组成
    for(int i = 0;i <= x;++i){
        for(int j = 0;j <= n;++j){
            if(i == 0 || j == 0){
                if(j == 0) ans_dp[i][j] = false;
                if(i == 0) ans_dp[i][j] = true;
                continue;
            }
            if(i - a[j] >= 0 && j != index)
                ans_dp[i][j] = ans_dp[i - a[j]][j - 1] || ans_dp[i][ j - 1];
            else
                ans_dp[i][j] = ans_dp[i][j - 1];    
        }
    }
}



int main(){
    std::cin>>n>>x;
    for(int i = 1;i <= n;++i)
        std::cin>>a[i];

    for(int i = 1;i <= n;++i){
//        memset(ans_dp,0,sizeof(ans_dp));
//        memset(flag,0,sizeof(flag));
        coin(i);
        if(ans_dp[x][n])
            flag[i] = true;
    }
    int count = 0;
    for(int i = 1;i <= n;++i)
        if(!flag[i]) count++;
    std::cout<<count<<std::endl;
    for(int i = 1;i <= n;++i)
        if(!flag[i]) std::cout<<a[i]<<' ';
    std::cout<<std::endl;    

    return 0;
}