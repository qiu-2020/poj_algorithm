#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        // write your code here
        //recursion
        int n = s.size(),ans = 0x3fffffff;
        vector<vector<bool>> g(n,vector<bool>(n,true));
        vector<int> f(n,0x3fffffff);
        for(int i = n - 1;i >= 0;--i){
            for(int j = n - 1;j >= 0;--j){
                if(i >= j) g[i][j] = true;
                else
                    g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];  
            }
        }
        for(int i = 0;i <= n - 1;++i){
            if(g[0][i]) f[i] = 0;
            else{
                for(int j = i - 1;j >= 0;--j){
                    if(g[j + 1][i])
                        f[i] = min(1 + f[j],f[i]);    
                }
            }
        }
        return f[n - 1];
    }
};


int main(){
    Solution s;
    string s1("a");
    string s2("aab");
    string s3("aaabaa");
    std::cout<<s.minCut(s1)<<std::endl;
    std::cout<<s.minCut(s2)<<std::endl;
    std::cout<<s.minCut(s3)<<std::endl;

    return 0;
}