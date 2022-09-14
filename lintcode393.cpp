#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(n <= 1) return 0;
        // int sell[k],buy[k];
        int sell[2],buy[2];
        // if(k > n) k = n;
        sell[0] = 0;sell[1] = 0;
        buy[0] = -prices[0],buy[1] = -prices[0];
        if(k > 1)
            for(int i = 1;i < n;++i){
                for(int j = 1;j < k;++j){
                    buy[j - 1] = max(-prices[i],buy[j - 1]);
                    sell[j - 1] = max(buy[j - 1] + prices[i], sell[j - 1]);
                    buy[j] = max(sell[j - 1] - prices[i],buy[j]);
                    sell[j] = max(sell[j],buy[j] + prices[i]);
                }
            }
        else  
            for(int i = 1;i < n;++i){
                buy[0] = max(-prices[i],buy[0]);
                sell[0] = max(buy[0] + prices[i], sell[0]);
            }   
        return sell[k - 1]; 
    }
};

int main(){
    int k1 = 2,k2 = 1,k3 = 1;
    vector<int> v1{4, 4, 6, 1, 1, 4, 2 ,5},v2{3, 2, 1},v3{3,4,8,5};
    Solution s;
    std::cout<<s.maxProfit(k1,v1)<<std::endl;
    std::cout<<s.maxProfit(k2,v2)<<std::endl;
    std::cout<<s.maxProfit(k3,v3)<<std::endl;
    return 0;
}