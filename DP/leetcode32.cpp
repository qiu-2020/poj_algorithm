#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        int n = s.length(),ans = 0,maxlen = 0;
        for(int i = 0;i < n;++i){
            if(s[i] == '(') st.push('(');
            if(s[i] == ')'){
                st.push(')');
                if(!st.empty() && st.top() == '('){
                    maxlen += 2;
                    st.pop(); st.pop();
                    if(maxlen > ans)
                        ans = maxlen;
                }
                else maxlen = 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str(")(((((()())()()))()(()))(");
    std::cout<<s.longestValidParentheses(str)<<std::endl;



    return 0;
}