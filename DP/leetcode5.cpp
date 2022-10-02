#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0,right = 0,n = s.length();
        bool flag = false;
        vector<vector<bool>> ans(n,vector<bool>(vector<bool>(n,false)));
        for(int i = 0;i < n;++i)
            ans[i][i] = true;
        for(int i = 0;i < n - 1;++i){
            if(s[i] == s[i + 1]){
                ans[i][i + 1] = true;
                left = i;
                right = i + 1;
            }    
        }
        for(int i = 2;i < n;++i){
            for(int j = 0;j < n - i;++j){
                if(s[j] == s[j + i] && ans[j + 1][j + i - 1]){
                    left = j;
                    right = j + i;
                    ans[j][j + i] = true;
                }
            }
        }
        return s.substr(left,right - left + 1);
    }
};

int main(){
    string s1{"babad"},s2{"cbbd"},s3{"ccc"},s4{"bb"};
    Solution s;
    std::cout<<s.longestPalindrome(s1)<<std::endl;
    std::cout<<s.longestPalindrome(s2)<<std::endl;
    std::cout<<s.longestPalindrome(s3)<<std::endl;
    std::cout<<s.longestPalindrome(s4)<<std::endl;


    return 0;
}