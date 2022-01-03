#include <iostream>

const int MAX_N = 3510;
const int MAX_M = 13010;
int N,M;
int W[MAX_N],D[MAX_N];
int ans[MAX_M][MAX_N];
int ans_dp[MAX_M];

void pack(void){
    for(int i = 0;i <= M;++i){
        for(int j = 0;j <= N;++j){
            if(i == 0 || j == 0){
                ans[i][j] = 0;
                continue;
            }
            if(i >= W[j]){
                ans[i][j] = std::max(ans[i - W[j]][j - 1] + D[j],ans[i][j - 1]);
            }
            else ans[i][j] = ans[i][j - 1];
        }
    }
}

void pack_r(void){
    for(int i = 1;i <= N;++i){ // 1 ~ N
        for(int j = M;j >= 0;--j){ // 1 ~ M
            if(i == 1){
                if(j >= W[i]) ans_dp[j] = D[i];
                else ans_dp[j] = 0;
                continue;
            }
            if(j - W[i] >= 0)
                ans_dp[j] = std::max(ans_dp[j], ans_dp[j - W[i]] + D[i]);
            else continue;    
        }
    }
}

int main(){
    std::cin>>N>>M;
    for(int i = 1;i <= N;++i)
        std::cin>>W[i]>>D[i];
    pack_r();    
    std::cout<<ans_dp[M]<<std::endl;
    return 0;
}