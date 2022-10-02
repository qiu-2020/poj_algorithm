#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1,0);
        // ans[0] = 1;
        ans[0] = 1, ans[1] = 1;
        for(int i = 2;i <= n;++i){
            for(int j = 0;j < i;++j){
                ans[i] += ans[j] * ans[i - 1 - j];
            }
        }
        return ans[n];
    }
};

int main(){

    Solution s;
    std::cout<<s.numTrees(3)<<std::endl;




    return 0;
}