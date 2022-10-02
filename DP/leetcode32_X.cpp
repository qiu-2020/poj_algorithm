#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(),max_len = 0;
        vector<vector<bool>> ans(n,vector<bool>(n,false));
        for(int i = 0;i < n;++i)
            if(s[i] == '(' && s[i + 1] == ')'){
                ans[i][i + 1] = true;
                // std::cout<<s.substr(i,2)<<std::endl;
                max_len = 2;
            }    
            else ans[i][i + 1] = false;    
    //##############################
        bool flag = false;  
        // if(n < 4) return max_len;
        for(int i = 3;i < n;i += 2){
            for(int j = 0;j < n - i;++j){
                for(int k = j + 1;k < j + i; k += 1){  
                    if(ans[j][k] && ans[k + 1][j + i]){
                        flag = true;
                        ans[j][j + i] = true;
                        std::cout<<s.substr(j,i + 1)<<std::endl;
                    }    
                }
                if((ans[j + 2][j + i] && is_pair(j,j + 1,s))|| (ans[j][j + i - 2] && is_pair(j + i - 1,j + i,s))|| (ans[j + 1][j + i - 1] && is_pair(j,j + i,s))){
                    ans[j][j + i] = true;
                    // std::cout<<s.substr(j,i - 1)<<std::endl;
                    flag = true;
                }    
            }
            if(flag){
                max_len += 2;
                flag = false;
            }    
            // else return max_len;    
        }  
        return max_len;
        // // for(int i = 0;i < )
    //###############################
    }

    bool is_pair(int i,int j,string s){
        if(s[i] == '(' && s[j] == ')') return true;
        else return false;
    }
};

int main(){
    Solution s;
    string str[4]{"(()",")()())","",")(((((()())()()))()(()))("};
    for(int i = 0;i < 4;++i){
        std::cout<<s.longestValidParentheses(str[i])<<std::endl;
    }    
    string str1{")()())()()("};
    std::cout<<s.longestValidParentheses(str1)<<std::endl;
    std::cout<<s.longestValidParentheses(")(((((()())()()))()(()))(")<<std::endl;


    return 0;
}

        // bool flag = false;  
        // // if(n < 4) return max_len;
        // for(int i = 3;i < n;i += 2){
        //     for(int j = 0;j < n - i;++j){
        //         for(int k = j + 2;k < j + i; k += 2){  
        //             if(ans[j][k - 1] && ans[k][j + i]){
        //                 flag = true;
        //                 ans[j][j + i] = true;
        //                 std::cout<<s.substr(j,i + 1)<<std::endl;
        //             }    
        //         }
        //         if((ans[j + 2][j + i] && is_pair(j,j + 1,s))|| (ans[j][j + i - 2] && is_pair(j + i - 1,j + i,s))|| (ans[j + 1][j + i - 1] && is_pair(j,j + i,s))){
        //             ans[j][j + i] = true;
        //             // std::cout<<s.substr(j,i - 1)<<std::endl;
        //             flag = true;
        //         }    
        //     }
        //     if(flag){
        //         max_len += 2;
        //         flag = false;
        //     }    
        //     // else return max_len;    
        // }  
        // return max_len;
        // // for(int i = 0;i < )