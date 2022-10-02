#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n + 10,0);
        ans[1] = 1;
        ans[2] = 2;
        for(int i = 3;i <= n;++i)
            ans[i] = ans[i - 1] + ans[i - 2];
        return ans[n];    
    }
};

int main(){
    int n1(2),n2(3);
    Solution s;
    std::cout<<s.climbStairs(n1)<<std::endl;
    std::cout<<s.climbStairs(n2)<<std::endl;


    return 0;
}