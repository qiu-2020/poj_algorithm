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
        int ans[n][3];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < 3;++j){
                if(i == 0){
                    ans[i][j] = costs[i][j];
                    continue;
                }
                if(j == 0)
                    ans[i][j] = min(ans[i - 1][1] + costs[i][j],ans[i - 1][2] + costs[i][j]);
                if(j == 1)
                    ans[i][j] = min(ans[i - 1][0] + costs[i][j],ans[i - 1][2] + costs[i][j]);
                if(j == 2)
                    ans[i][j] = min(ans[i - 1][0] + costs[i][j],ans[i - 1][1] + costs[i][j]);    
            }
        }
        int a = ans[n - 1][0];
        for(int i = 1;i < 3;++i)
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