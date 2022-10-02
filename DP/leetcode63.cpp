#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans[0][0] = (obstacleGrid[0][0] == 0)? 1 : 0;
        for(int i = 1;i < m;++i){
            ans[i][0] = 1;
            if(obstacleGrid[i][0] == 1) ans[i][0] = 0;
            if(ans[i - 1][0] == 0) ans[i][0] = 0;
        } 
        for(int i = 1;i < n;++i){
            ans[0][i] = 1;
            if(obstacleGrid[0][i] == 1) ans[0][i] = 0;
            if(ans[0][i - 1] == 0) ans[0][i] = 0;
        }       

        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                if(obstacleGrid[i][j] == 1) ans[i][j] = 0;
                else ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
        return ans[m - 1][n - 1];
    }
};

int main(){
    vector<vector<int>> o1{{0,0,0},{0,1,0},{0,0,0}},o2{{0,1},{0,0}},o3{{1,0}};
    Solution s;
    std::cout<<s.uniquePathsWithObstacles(o1)<<std::endl;
    std::cout<<s.uniquePathsWithObstacles(o2)<<std::endl;
    std::cout<<s.uniquePathsWithObstacles(o3)<<std::endl;
    return 0;
}