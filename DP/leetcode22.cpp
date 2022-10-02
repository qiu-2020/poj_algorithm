#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(n,n,"",ans);
        return ans;
    }
    // static vector<string> ans;
    void recursion(int left_n,int right_n,string res,vector<string>& ans){
        // extern vector<string> ans;
        if(left_n == 0 && right_n == 1){
            res += ')';
            ans.push_back(res);
            return;
        }
        else{
            if(left_n != 0 && left_n <= right_n){
                res += '(';
                recursion(left_n - 1,right_n,res,ans);
                res = res.substr(0,res.length() - 1);
            }
            if(right_n > 1 && left_n < right_n){
                res += ')';
                recursion(left_n,right_n - 1,res,ans);
                res = res.substr(0,res.length() - 1);
            }
        }
    }
};

int main(){
    int n[2]{3,1};
    Solution s;
    for(int i = 0;i < 2;++i){
        auto ans = s.generateParenthesis(n[i]);
        for(auto it = ans.begin();it != ans.end();it++){
            std::cout<<*it<<' ';
        }
        std::cout<<std::endl;
    }


    return 0;
}