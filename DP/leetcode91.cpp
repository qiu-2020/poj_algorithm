#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> ans(n + 1,0);
        if(s[0] == '0'){
            ans[0] = 0;
            return 0;
        }    
        else ans[0] = 1;
        if((s[1] >= '0' && s[1] <= '6' && s[0] == '2') || (s[0] == '1' && s[1] >= '0' && s[1] <= '9')){
            if(s[1] == '0') ans[1] = 1;
            else ans[1] = 2;
        }
        else{
            if(s[0] == '0') ans[1] = 0;
            else if(s[1] == '0' && s[0] != '1' && s[0] != '2') 
                ans[1] = 0;
            else    
                ans[1] = 1;    
        }

        for(int i = 2;i < n;++i){
            if(s[i] == '0'){
                if(s[i - 1] >= '1' && s[i - 1] <= '2')
                    ans[i] = ans[i - 2];
                else{
                    ans[i] = 0;
                    // return 0;
                }    
            }
            else{
                if((s[i] >= '0' && s[i] <= '6' && s[i - 1] == '2') || (s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9'))
                    ans[i] = ans[i - 1] + ans[i - 2];
                // else if(s[i - 1] == '0')
                //     ans[i] = ans[i - 1];
                else ans[i] = ans[i - 1];    
            }
        }
        return ans[n - 1];
    }
};

int main(){
    // string s[6] = {"227","2611055971756562","10","12","226","06"};
    Solution sol;
    // for(int i = 0;i < 6;++i){
    //     std::cout<<sol.numDecodings(s[i])<<std::endl;
    // }
    string s("301");
    std::cout<<sol.numDecodings(s)<<std::endl;



    return 0;
}