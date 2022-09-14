#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int n1(word1.length()),n2(word2.length());
        if(n1 == 0 || n2 == 0)
            return (n1 == 0)? n2 : n1;
        int dp[n1][n2];
        if(word1[0] == word2[0])
            dp[0][0] = 0;
        else dp[0][0] = 1;    
        for(int i = 1;i < n2;++i){
            if(word1[0] == word2[i])
                dp[0][i] = dp[0][i - 1];
            else
                dp[0][i] = dp[0][i - 1] + 1;    
        }
        
        for(int i = 1;i < n1;++i){
            if(word1[i] == word2[0])
                dp[i][0] = dp[i - 1][0];
            else
                dp[i][0] = dp[i - 1][0] + 1;   
        }
        int tmp = 0;
        for(int i = 1;i < n1;++i){
            for(int j = 1;j < n2;++j){
                tmp = min(dp[i - 1][j - 1],min(dp[i][j - 1],dp[i - 1][j]));
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = tmp + 1;    
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};

int main(){
    Solution s;
    string word1[2]{"horse","intention"},word2[2]{"ros", "execution"};
    for(int i = 0;i < 2;++i)
        std::cout<<s.minDistance(word1[i],word2[i])<<std::endl;
    return 0;
}