#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i = 0;i < n;++i)
            ans[0][i] = 1;
        for(int i = 0;i < m;++i)
            ans[i][0] = 1;   
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
        return ans[m - 1][n - 1];
    }
};

int main(){
    int m1(3),n1(7),m2(3),n2(2);
    Solution s;
    std::cout<<s.uniquePaths(m1,n1)<<std::endl;
    std::cout<<s.uniquePaths(m2,n2)<<std::endl;

    return 0;
}