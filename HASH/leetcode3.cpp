#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0,right = 0,ans = 0;
        int l = s.length();
        unordered_map<char,int> map;
        while(right < l){
            if(map[s[right]] == 0){
                map[s[right]]++;
                if(right - left + 1 > ans)
                    ans = right - left + 1;
                ++right;    
            }
            else{
                while(map[s[right]] > 0){
                    map[s[left]]--;
                    ++left;
                }
                ++map[s[right]];
                ++right;
            }
        }
        return ans;
    }
};

int main(){
    string s1("abcabcbb"),s2("bbbbb"),s3("pwwkew");
    Solution s;
    std::cout<<s.lengthOfLongestSubstring(s1)<<std::endl;
    std::cout<<s.lengthOfLongestSubstring(s2)<<std::endl;
    std::cout<<s.lengthOfLongestSubstring(s3)<<std::endl;


    return 0;
}