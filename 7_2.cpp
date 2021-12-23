#include <iostream>
#include <cstring>

const int MAX = 110;
int n,k;
int position[MAX];
int profit[MAX];
int ans[MAX];

void profit_dp(void){
    ans[1] = profit[1]; ans[0] = 0;
    for(int i = 1;i <= n;++i){ //决定当前i这个位置开设不开设
        for(int j = i - 1;j >= 0;--j){
            if(position[i] - k > position[j]){
                ans[i] = std::max(ans[j] + profit[i],ans[i]);
            }
            else{
                int max_t = std::max(profit[i],ans[j]);
                ans[i] = std::max(max_t,ans[i]);
            }
        }
    }
}

int main(){
    int T;
    std::cin>>T;
    for(int i = 0;i < T;++i){
        std::cin>>n>>k;
        memset(ans,0,sizeof(ans));
        for(int j = 1;j <= n;++j)
            std::cin>>position[j];
        for(int j = 1;j <= n;++j)
            std::cin>>profit[j];
        profit_dp();    
        std::cout<<ans[n]<<std::endl;
    }

    return 0;
}