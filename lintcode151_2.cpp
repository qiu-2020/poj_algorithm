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
        int n = prices.size(),ans;
        if(n == 0 || n == 1) return 0; 
        int buy1,buy2,sell1,sell2;
        buy1 = -prices[0],buy2 = -prices[0];
        sell1 = 0,sell2 = 0;
        for(int i = 1;i < n;++i){
            buy1 = max(buy1,-prices[i]);
            sell1 = max(sell1,buy1 + prices[i]);
            buy2 = max(sell1 - prices[i],buy2);
            sell2 = max(buy2 + prices[i],sell2);
        }
        return sell2;
    }
};

int main(){
    Solution s;
    vector<int> v1{4,4,6,1,1,4,2,5};
    vector<int> v2{1,2};
    vector<int> v3{1,2,4};
    std::cout<<s.maxProfit(v3)<<std::endl;


    return 0;
}