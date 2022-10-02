#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans;
        // for(auto it = nums.begin();it != nums.end();++it)
        //     m[*it] = *it;
        // for(auto it = m.begin();it != m.end();++it){
        //     complement = target - it->second;
        //     if(m.find(complement) == m.end())
        //         return vector<int>{}
        // }
        for(int i = 0;i < nums.size();++i){
            if(m.find(target - nums[i]) != m.end()){
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
            }
            m[nums[i]] = i;
        }
        if(!ans.empty()) return ans;
        else return vector<int>{-1,-1};
    }
};

int main(){
    vector<int> n1{2,7,11,15},n2{3,2,4},n3{3,3};
    int t1{9},t2{6},t3{6};
    Solution s;
    cout<<s.twoSum(n1,t1)[0]<<s.twoSum(n1,t1)[1]<<endl;
    cout<<s.twoSum(n2,t2)[0]<<s.twoSum(n2,t2)[1]<<endl;
    cout<<s.twoSum(n3,t3)[0]<<s.twoSum(n2,t2)[1]<<endl;
    return 0;
}