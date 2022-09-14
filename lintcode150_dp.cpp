#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    // std::vector<int> ans;
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size() == 0) return 0;
        int n = prices.size(),dp[n][2],ans = 0x80808080;
        memset(dp,0x80,sizeof(dp));
        dp[0][0] = 0x0;dp[0][1] = -prices[0];
        ans = max(dp[0][0],dp[0][1]);
        for(int i = 1;i < n;++i){
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] - prices[i]);
            if(dp[i][0] > ans) ans = dp[i][0];
            if(dp[i][1] > ans) ans = dp[i][1];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> p1{2,1,2,0,1},p2{4,3,2,1};
    std::cout<<s.maxProfit(p1)<<std::endl;
    std::cout<<s.maxProfit(p2)<<std::endl;


    return 0;
}