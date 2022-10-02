#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash.insert(pair<int,int>(0,1));
        int n = nums.size();
        int sum_i = 0,ans = 0;
        for(int i = 0;i < n;++i){
            sum_i += nums[i];
            if(hash.find(sum_i - k) != hash.end())
                ans += hash[sum_i - k];
            if(hash.find(sum_i) != hash.end())
                hash[sum_i] += 1;
            else        
                hash.insert(pair<int,int>(sum_i,1));    
        }
        return ans;
    }
};

int main(){
    vector<int> num1{1,1,1},num2{1,2,3},num3{1,-1,0};
    int k1 = 2,k2 = 3,k3 = 0;
    Solution s;
    std::cout<<s.subarraySum(num1,k1)<<std::endl;
    std::cout<<s.subarraySum(num2,k2)<<std::endl;
    std::cout<<s.subarraySum(num3,k3)<<std::endl;


    return 0;
}