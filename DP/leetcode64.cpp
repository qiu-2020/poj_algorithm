#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans[0][0] = grid[0][0];
        for(int i = 1;i < n;++i)
            ans[0][i] = ans[0][i - 1] + grid[0][i];
        for(int i = 1;i < m;++i)    
            ans[i][0] = ans[i - 1][0] + grid[i][0];

        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                ans[i][j] = min(ans[i - 1][j],ans[i][j - 1]) + grid[i][j];
            }
        }
        return ans[m - 1][n - 1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> g1{{1,3,1},{1,5,1},{4,2,1}},g2{{1,2,3},{4,5,6}};
    std::cout<<s.minPathSum(g1)<<std::endl;
    std::cout<<s.minPathSum(g2)<<std::endl;

    return 0;
}