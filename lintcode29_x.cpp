#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        int l1(s1.length()),l2(s2.length()),l3(s3.length());
        bool dp[l1 + 1][l2 + 1];//第三个分量0、1代表k-1和k
        dp[0][0] = true;
        for(int i = 1;i <= l1;++i){
            if(s1[i] == s3[i] && dp[0][i - 1]) dp[0][i] = true;
            else dp[0][i] = false;
        }
        for(int i = 0;i <= l2;++i){
            if(s2[i] == s3[i] && dp[i - 1][0]) dp[i][0] = true;
            else dp[i][0] = false;
        }

        for(int i = 1;i <= l2;++i){
            for(int j = 1;j <= l1;++j){
                dp[i][j] = (dp[i - 1][j] && s1[i] == s3[i + j]) || (dp[i][j - 1] && s1[j] == s3[i + j]);
            }
        }
        return dp[l1][l2];
    }
};

// std::string s1,s2,s3;
// int l1,l2,l3;

// bool r_str(int i1,int i2,int i3){
//     if(i1 >= l1 && i2 >= l2 && i3 < l3 || s3[i3] != s1[i1] && s3[i3] != s2[i2]) return false;
//         //目标字符串还有没匹配的
//     else if(i1 >= l1 && i2 >= l2 && i3 >= l3)
//         return true;
//     else{
//         //尝试用A匹配X；然后用B匹配X；
//         return ((s1[i1] == s3[i3]) && r_str(i1 + 1,i2,i3 + 1)) || ((s2[i2] == s3[i3]) && r_str(i1,i2 + 1,i3 + 1));
//     }    
// }





int main(){
    // std::cin>>s1>>s2>>s3;
    // l1 = s1.length(),l2 = s2.length(),l3 = s3.length();
    // string s11("aabcc"),s12("dbbca"),s13("aadbbcbcac");
    // string s21(""),s22(""),s23("1");
    // string s31("aabcc"),s32("dbbca"),s33("aadbbbaccc");
    string s1[3]{"aabcc","","aabcc"},s2[3]{"dbbca","","dbbca"},s3[3]{"aadbbcbcac","1","aadbbbaccc"};
    Solution s;
    for(int i = 0;i < 3;++i){
        if(s.isInterleave(s1[i],s2[i],s3[i]))
            std::cout<<"true"<<std::endl;
        else    
            std::cout<<"false"<<std::endl;   
    }
    return 0;
}