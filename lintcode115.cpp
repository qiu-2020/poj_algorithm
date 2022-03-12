#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        int row = obstacleGrid.size(),col = obstacleGrid[0].size();
        int ans[row][col];
        if(obstacleGrid[0][0] == 1) return 0;
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j){
                if(i == 0 && j == 0){
                    ans[i][j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    ans[i][j] = 0;
                    continue;
                }
                if(i == 0){
                    ans[i][j] = ans[i][j - 1];
                    continue;
                }
                if(j == 0){
                    ans[i][j] = ans[i - 1][j];
                    continue;
                }
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
        return ans[row - 1][col - 1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> obstacleGrid1 = {{0}};
    vector<vector<int>> obstacleGrid2 = {{0,0,0},{0,1,0},{0,0,0}};
    std::cout<<s.uniquePathsWithObstacles(obstacleGrid1)<<std::endl;

    return 0;
}