#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        // write your code here
        int ans[n + 1];
        memset(ans,0x3f3f3f3f,sizeof(ans));
        ans[1] = 1,ans[0] = 0;
        for(int i = 2;i <= n;++i){
            for(int j = i - 1;j >= 1;--j){
                if(j * j <= i)
                    ans[i] = min(ans[i - j * j] + 1,ans[i]);
            }
        }
        return ans[n];
    }
};




int main(){
    Solution s;
    int n1 = 12,n2 = 13,n3 = 4;
    std::cout<<s.numSquares(n1)<<std::endl;
    std::cout<<s.numSquares(n2)<<std::endl;
    std::cout<<s.numSquares(n3)<<std::endl;



    return 0;
}