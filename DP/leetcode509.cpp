#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        int ans[n + 10];
        ans[0] = 0,ans[1] = 1,ans[2] = 1;
        for(int i = 3;i <= n;++i)
            ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1];
        return ans[n];    
    }
};
int main(){
    int n1{25},n2{4};
    Solution s;
    std::cout<<s.tribonacci(n2)<<std::endl;



    return 0;
}