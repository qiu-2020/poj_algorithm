#include <iostream>
#include <cstring>
#include <vector>

int n,x;
int coins[210];
int dp[10010];
int ans[210];

std::vector<int> v;

void required_coins(){
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    dp[0] = 1;
    for(int i = 1;i <= n;++i){
        for(int j = x;j >= 0;--j){
            if(j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];    
        }
        //对于j元多少种组成方法
    }
//   0 1 2 3
// 1 1 1 0 0
// 2 1 1 1 1
    ans[0] = 0;
    int c = 0;
    for(int i = 0;i <= n;++i){
        for(int j = 0;j <= x;++j){
            if(j >= coins[i])
                ans[j] = dp[j] - ans[j - coins[i]];
            else
                ans[j] = dp[j];    

        }
        if(ans[x] == 0){
            c++;
            v.push_back(coins[i]);
        }

    }

    // for(int i = 1;i <= n;++i){
    //     if(ans[i] == 0)
    //         c++;
    //     v.push_back(coins[i]);    
    // }
    std::cout<<c<<std::endl;
    for(auto it = v.begin();it != v.end();++it)
        std::cout<<*it<<' ';
    std::cout<<std::endl;    

}


int main(){
    std::cin>>n>>x;
    for(int i = 1;i <= n;++i)
        std::cin>>coins[i];

    required_coins();

    return 0;
}