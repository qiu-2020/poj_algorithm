#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n,false);
        ans[0] = true;
        for(int i = 1;i < n;++i){
            for(int j = i - 1;j >= 0;--j){
                if(ans[j] && j + nums[j] >= i){
                    ans[i] = true;  
                    break;  
                }    
            }
        }
        return ans[n - 1];
    }
};

int main(){
    vector<int> n1{2,3,1,1,4},n2{3,2,1,0,4};
    Solution s;

    if(s.canJump(n1))
        std::cout<<"true"<<std::endl;
    else std::cout<<"false"<<std::endl;

    if(s.canJump(n2))
        std::cout<<"true"<<std::endl;
    else std::cout<<"false"<<std::endl;



    return 0;
}