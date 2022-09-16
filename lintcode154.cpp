#include <iostream>
#include <string>
using namespace std;

//#################################################
std::string s1,s2;
int l1,l2;

bool isMatch(int i,int j){
    if(i >= l1 || j >= l2)
        if(i >= l1 && j >= l2)
            return true;
        else return false;    
    else if(s2[j + 1] == '*'){
        if(s2[j] == s1[i] || s2[j] == '.')
        //匹配一个(j + 2,i + 1)，匹配多个(i + 1,j),不匹配(i,j + 2)
            return isMatch(i + 1,j + 2) || isMatch(i + 1,j) || isMatch(i,j + 2);
        else if(s2[j] != s1[i])
            return isMatch(i,j + 2);    
        else return false;    
    }    
    else if(s2[j] == '.' && i < l1 || s2[j] == s1[i])
        return isMatch(i + 1,j + 1);
    else return false;    
}
//#################################################

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        int count = 0;
        for(int i = 0;i < p.length();++i)
            if(p[i] == '*') ++count;
        int l1 = s.length(),l2 = p.length() - count;
        bool dp[l1 + 1][l2 + 1],flag = false;
        dp[0][0] = true;
        for(int i = 0;i < l2 + 1;++i)
            if(p[i] != '*' && p[i + 1] == '*' && flag == false){
                dp[0][i] = true;
                flag = true;
            }
            else dp[0][i] = false;
        for(int i = 0;i < l1 + 1;++i)
            dp[i][0] = false;
        for(int i = 0;i <= l1;++i){
            for(int j = 0;j <= l2;++j){
                if(p[j] == '*'){
                    if(p[j - 1] == s[i] || p[j - 1] == '.')
                        dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 2];    
                }
                else if(p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j] != '.' && p[j] != '*'){
                    if(p[j] == s[i]) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = false;
                }        
            }
        }
        return dp[l1][l2];
    }
};

int main(){

    //################################################
    // std::cin>>s1>>s2;
    // l1 = s1.length(),l2 = s2.length();
    // if(isMatch(0,0)) std::cout<<"true"<<std::endl;
    // else std::cout<<"false"<<std::endl;
    //################################################

    Solution s;
    string s[7]{"aa","aa","aaa","aa","aa","ab","aab"},p[7]{"a","aa","aa","a*",".*",".*","c*a*b*"};
    for(int i = 0;i < 7;++i){
        // if(s.isMatch(s[i],p[i]))
    }


    return 0;
}