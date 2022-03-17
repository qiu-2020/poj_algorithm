#include <iostream>
#include <cstring>

const int MAX_N = 510;
const int MAX_F = 10010;
int T,E,F,N,sum_coins;
int coins[MAX_N][2];
// coins[][0] : W coins[][1] : P
int ans[MAX_N][MAX_F];

// ans[i][j] = min(ans[i - 1][j],ans[i][j - coins[i][0]] + coins[i][1])


void piggy_bank(){
    for(int i = 1;i <= N;++i){
        for(int j = 0;j <= sum_coins;++j){
            if(j - coins[i][1] > 0)
                ans[i][j] = std::min(ans[i - 1][j],ans[i][j - coins[i][1]] + coins[i][0]);
            else if(j - coins[i][1] == 0){
                ans[i][j] = std::min(coins[i][0],ans[i - 1][j]);
            }    
            else
                ans[i][j] = ans[i - 1][j];        
        }
    }
}

int main(){
    std::cin>>T;
    for(int i = 0;i < T;++i){
        std::cin>>E>>F>>N;
        sum_coins = F - E;
        for(int j = 1;j <= N;++j)
            std::cin>>coins[j][0]>>coins[j][1];
        memset(ans,0x3f,sizeof(ans));
        piggy_bank();
        if(ans[N][sum_coins] == 0x3f3f3f3f)
            std::cout<<"This is impossible."<<std::endl;
        else
            std::cout<<"The minimum amount of money in the piggy-bank is "<<ans[N][sum_coins]<<'.'<<std::endl;    
    }


    return 0;
}