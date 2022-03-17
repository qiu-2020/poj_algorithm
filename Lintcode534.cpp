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
    }
};

int  main(){
    Solution s;
    vector<int> input1({3,6,4}),input2({2,3,2,3});
    std::cout<<s.houseRobber2(input1)<<std::endl;
    std::cout<<s.houseRobber2(input2)<<std::endl;
    return 0;
}