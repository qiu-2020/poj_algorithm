#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum_i(n,0);
        // vector<int> sum_i_min(n,0x3f3f3f3f);
        int min_i = nums[0],ans = nums[0];
        sum_i[0] = nums[0];
        for(int i = 1;i < n;++i){
            sum_i[i] = sum_i[i - 1] + nums[i];
            ans = max(ans,max(sum_i[i] - min_i,sum_i[i]));
            // ans[i] = sum_i[i] - min_i;
            min_i = min(min_i,sum_i[i]); 
        }    
        // for(int i = 0;i < n;++i){
        //     sum_i[i] -= sum_i_min[i];
        // }
        return ans;
    }
};

int main(){
    vector<int> n1{-2,1,-3,4,-1,2,1,-5,4},n2{5,4,-1,7,8},n3{1};
    Solution s;
    std::cout<<s.maxSubArray(n1)<<std::endl;
    std::cout<<s.maxSubArray(n2)<<std::endl;
    std::cout<<s.maxSubArray(n3)<<std::endl;



    return 0;
}