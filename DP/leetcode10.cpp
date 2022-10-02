#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(),l2 = p.length();
        s = ' ' + s; p = ' ' + p;
        bool ans[l2 + 1][l1 + 1];
        for(int i = 0;i <= l1;++i)
            ans[0][i] = false;
        ans[0][0] = true;    
        for(int i = 1;i <= l2;++i)
            if(p[i] == '*')
                ans[i][0] = ans[i - 2][0];
            else ans[i][0] = false;
        for(int i = 1;i <= l2;++i){
            for(int j = 1;j <= l1;++j){
                if(p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.'))
                    ans[i][j] = ans[i][j - 1] || ans[i - 2][j - 1] || ans[i - 2][j];
                else if(p[i] == '*' && !(p[i - 1] == s[j] || p[i - 1] == '.'))    
                    ans[i][j] = ans[i - 2][j];
                else if(p[i] == '.' || (p[i] == s[j]))
                    ans[i][j] = ans[i - 1][j - 1];
                else ans[i][j] = false;       
            }
        }
        return ans[l2][l1];
    }
};

int main(){
    string s[3]{"aa","aa","ab"},p[3]{"a","a*",".*"};
    Solution sol;
    for(int i = 0;i < 3;++i){
        if(sol.isMatch(s[i],p[i]))
            std::cout<<"true"<<std::endl;
        else std::cout<<"false"<<std::endl;
    }    

    return 0;
}