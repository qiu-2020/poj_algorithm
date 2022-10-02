#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len_tmp(0),ans(0),p_last(0);
        stack<char> st;
        for(int i = 0;i < s.length();++i){
            if(st.size() > p_last){
                p_last = st.size();
                len_tmp = 0;
            }
            if(s[i] == '(') st.push('(');
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    len_tmp += 2;
                    if(len_tmp > ans)
                        ans = len_tmp;
                }    
                // if(st.size() > )
                else{
                    st.push(s[i]);
                    len_tmp = 0;
                }
            }     
        }
        return ans;
    }
};

int main(){
    string s1{"(()"},s2{")()())"},s3{""},s4{"()(()"};
    Solution s;
    std::cout<<s.longestValidParentheses(s1)<<std::endl;
    std::cout<<s.longestValidParentheses(s2)<<std::endl;
    std::cout<<s.longestValidParentheses(s3)<<std::endl;
    std::cout<<s.longestValidParentheses(s4)<<std::endl;



    return 0;
}