#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        int dp[n][2][3],ans;
        memset(dp,0,sizeof(dp));
        //第三个下标0代表没有买卖过，1代表买卖过一次，2代表买卖过两次
        dp[0][0][0] = 0,dp[0][1][0] = -prices[0];
        ans = max(dp[0][0][0],dp[0][1][0]);
        for(int i = 1;i < n;++i){
            dp[i][0][0] = max(dp[i - 1][0][0],dp[i - 1][1][0] + prices[i]);
            dp[i][0][1] = max(dp[i - 1][0][1],dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2],dp[i - 1][1][1] + prices[i]);
            int tmp = max(dp[i - 1][1][0],dp[i - 1][0][0] - prices[i]);
            dp[i][1][0] = tmp;
            tmp = max(dp[i - 1][1][0],dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(tmp,dp[i][0][1] - prices[i]);
            // tmp = max(dp[i - 1][1][2],dp[i - 1][0][2] - prices[i]);
            // dp[i][1][2] = max(tmp,dp[i][0][1] - prices[i]);
            dp[i][1][2] = dp[i - 1][1][2];
        }
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 2;++j)
            ans = max(ans,dp[n - 1][j][i]);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> p1{4,4,6,1,1,4,2,5};
    std::cout<<s.maxProfit(p1)<<std::endl;

    return 0;
}