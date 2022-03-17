#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    //ans[i] 选择i时的最大值
    long long houseRobber(vector<int> &A) {
        int len = A.size();
        if(len == 0) return 0;
        if(len == 1) return A[0];
        int ans[len];
        ans[0] = A[0],ans[1] = max(A[0],A[1]);
        for(int i = 2;i < len;++i){
// i个物品要或不要的最大值
            ans[i] = max(ans[i - 2] + A[i],ans[i - 1]);
        }
        return ans[len - 1];      
    }


};

int main(){
    vector<int> input1 = {3, 8, 4},input2 = {5, 2, 1, 3};
    Solution s;
    std::cout<<s.houseRobber(input1)<<std::endl;
    std::cout<<s.houseRobber(input2)<<std::endl;



    return 0;
}