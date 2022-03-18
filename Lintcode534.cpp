#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        int ans1[len],ans2[len];
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return std::max(nums[0],nums[1]);
        if(len == 3) return std::max(std::max(nums[0],nums[1]),nums[2]);



        ans1[0] = nums[0];ans1[1] = std::max(nums[0],nums[1]);
        for(int i = 2;i < len - 1;++i){
            ans1[i] = std::max(ans1[i - 1],ans1[i - 2] + nums[i]);
        }

        ans2[1] = nums[1];ans2[2] = std::max(nums[1],nums[2]);
        for(int i = 3;i < len;++i){
            ans2[i] = std::max(ans2[i - 1],ans2[i - 2] + nums[i]);
        }
        return std::max(ans1[len - 2],ans2[len - 1]);                    
    }

};


int  main(){
    Solution s;
    vector<int> input1({3,6,4}),input2({2,3,2,3}),input3({1,3,2,1,5}),input4({828,125,740,724,983,321,773,678,841,842,875,377,674,144,340,467,625,916,463,922,255,662,692,123,778,766,254,559,480,483,904,60,305,966,872,935,626,691,832,998,508,657,215,162,858,179,869,674,452,158,520,138,847,452,764,995,600,568,92,496,533,404,186,345,304,420,181,73,547,281,374,376,454,438,553,929,140,298,451,674,91,531,685,862,446,262,477,573,627,624,814,103,294,388});
    std::cout<<s.houseRobber2(input1)<<std::endl;
    std::cout<<s.houseRobber2(input2)<<std::endl;
    std::cout<<s.houseRobber2(input3)<<std::endl;
    std::cout<<s.houseRobber2(input4)<<std::endl;

    return 0;
}