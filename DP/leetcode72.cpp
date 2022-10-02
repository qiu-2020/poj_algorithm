#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(),l2 = word2.length();
        //l2 \ l1
        int ans[l2 + 1][l1 + 1];
        memset(ans,0,sizeof(ans));
        for(int i = 0;i <= l1;++i)
            ans[0][i] = i;
        for(int i = 0;i <= l2;++i)
            ans[i][0] = i;      
        for(int i = 1;i <= l2;++i){
            for(int j = 1;j <= l1;++j){
                if(word1[j - 1] == word2[i - 1])
                    ans[i][j] = ans[i - 1][j - 1];
                else
                    ans[i][j] = std::min(std::min(ans[i - 1][j - 1],ans[i][j - 1]),ans[i - 1][j]) + 1;
            }
        }
        return ans[l2][l1];
    }
};

int main(){
    string word1("horse"),word2("ros");
    Solution s;
    std::cout<<s.minDistance(word1,word2)<<std::endl;


    return 0;
}