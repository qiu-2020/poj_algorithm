#include <iostream>
#include <vector>
using namespace std;

// class Solution1 {
// public:
//     /**
//      * @param nums: An array of non-negative integers.
//      * @return: The maximum amount of money you can rob tonight
//      */
//     int houseRobber2(vector<int> &nums) {
//         // write your code here
//         return recursion_robber2(nums,0,false);
//     }
//     int recursion_robber2(vector<int> &nums,int i,bool flag){
//         if(i == (nums.size() - 1) && flag || i >= nums.size()) return 0;
//         if(i == (nums.size() - 1) && !flag) return nums[i];
//         if(i == 0)
//             return max(recursion_robber2(nums,i + 2,true) + nums[i],recursion_robber2(nums,i + 1,false));
//         else return max(recursion_robber2(nums,i + 2,flag) + nums[i],recursion_robber2(nums,i + 1,flag));    
//     }
 
// };

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here
    }
};

int  main(){
    Solution s;
    vector<int> input1({3,6,4}),input2({2,3,2,3});
    std::cout<<s.houseRobber2(input1)<<std::endl;
    std::cout<<s.houseRobber2(input2)<<std::endl;
    return 0;
}