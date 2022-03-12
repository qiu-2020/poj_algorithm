#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        if(n == 0) return 0;
        int k = costs[0].size();
        int ans[n][k];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < k;++j){
                if(i == 0){
                    ans[i][j] = costs[i][j];
                    continue;
                }
                ans[i][j] = 999999;
                for(int k1 = 0;k1 < k;++k1){
                    if(k1 != j){
                        ans[i][j] = min(ans[i - 1][k1] + costs[i][j],ans[i][j]);
                    }
                }
            }
        }
        int a = ans[n - 1][0];
        for(int i = 1;i < k;++i)
            if(ans[n - 1][i] < a)
                a = ans[n - 1][i];
        return a;        
    }
};

int main(){
    Solution s;
    vector<vector<int>> i1 = {{14,2,11},{11,14,5},{14,3,10}},i2 = {{1,2,3},{1,4,6}};
    std::cout<<s.minCost(i1)<<std::endl;
    cout<<s.minCost(i2)<<endl;

    return 0;
}