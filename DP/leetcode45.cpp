#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0x3f3f);
        ans[0] = 0;
        for(int i = 1;i < n;++i){
            for(int j = i - 1;j >= 0;--j){
                if(nums[j] + j >= i)
                    ans[i] = min(ans[i],1 + ans[j]);
            }
        }
        return ans[n - 1];
    }
};

int main(){
    vector<int> n1[2]{{2,3,1,1,4},{2,3,0,1,4}};
    Solution s;
    std::cout<<s.jump(n1[0])<<std::endl;
    std::cout<<s.jump(n1[1])<<std::endl;


    return 0;
}