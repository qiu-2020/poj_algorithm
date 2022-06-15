#include <iostream>
#include <cstring>
#include <vector>


int coins[210];
int n,x;
// bool ans[210];

bool is_required_r(int index,int count,int i){
    // || (count != x && i > n)
    if(count == x) return false;
    else if(i > n) return true;
    if(i == index) return is_required_r(index,count,i + 1);
    return is_required_r(index,count + coins[i],i + 1) && is_required_r(index,count,i + 1);
}

bool ans_dp[210][10010];


void is_required(int index){
    memset(ans_dp,0,sizeof(ans_dp));
    for(int i = 0;i < n;++i)
        ans_dp[i][0] = true;      
    if(index != 0)    
        for(int i = 1;i <= x;++i)    
            if(coins[0] == i) ans_dp[0][i] = true;
            else ans_dp[0][i] = false;
    
    else{
        for(int i = 1;i <= x;++i)    
            ans_dp[0][i] = false;
            // if(coins[0] == i) ans_dp[0][i] = true;
            // else ans_dp[0][i] = ans_dp[0][i - 1];
    }
    for(int i = 1;i < n;++i){
        for(int j = 1;j <= x;++j){
            if(i == index)
                ans_dp[i][j] = ans_dp[i - 1][j];
            else{
                if(j - coins[i] >= 0)
                    ans_dp[i][j] = ans_dp[i - 1][j] || ans_dp[i - 1][j - coins[i]];
                else ans_dp[i][j] = ans_dp[i - 1][j];
            }    
        }
    }

    return;
}

int ans[10010];
int dp[10010];

void coins_count(){
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    dp[0] = 1;
    for(int i = 0;i <= n;++i)
        for(int j = x;j >= coins[i];--j)
            dp[j] += dp[j - coins[i]];

    for(int i = 0;i <= n;++i){
        for(int j = 0;j <= x;++j)
            if(j >= coins[i])
                ans[j] = dp[j] - ans[j - coins[i]];
            else
                ans[j] = dp[j];    
    }

}


int main(){
    std::cin>>n>>x;
    for(int i = 1;i <= n;++i){
        std::cin>>coins[i];
    }
    std::vector<int> v;
    for(int i = 0;i < n;++i){
        is_required(i);
        ans[i] = ans_dp[n - 1][x];
    }

    int c = 0;
    for(int i = 0;i < n;++i){
        if(!ans[i]){
            c++; 
            v.push_back(coins[i]);
        }

    }
    std::cout<<c<<std::endl;
    for(auto it = v.begin();it != v.end();++it)
        std::cout<<*it<<' ';
    std::cout<<std::endl;    

    return 0;
}