#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void recursion(std::string digits,unordered_map<char,string> map,int i,std::string str,vector<string> &ans){
        if(i == digits.size()){
            ans.push_back(str);
            return;
        }    
        else{
            for(int j = 0;j < map[digits[i]].size();++j)
                recursion(digits,map,i + 1,str + map[digits[i]][j],ans);
        }
    }      

    vector<string> letterCombinations(string digits){
            unordered_map<char,string> map;
            map['2'] = "abc";
            map['3'] = "def";
            map['4'] = "ghi";
            map['5'] = "jkl";
            map['6'] = "mno";
            map['7'] = "pqrs";
            map['8'] = "tuv";
            map['9'] = "wxyz";

            vector<string> ans;
            if(digits == "") return ans;
            else{
                recursion(digits,map,0,"",ans);
                return ans;
            }    
    }

};
    
int main(){
    string d[3]{"23","","2"};
    Solution s;
    for(int i = 0;i < 3;++i){
        vector<string> ss(s.letterCombinations(d[i]));
        for(auto it = ss.begin();it < ss.end();it++){
            cout<<*it<<' ';
        }
        cout<<endl;
    }


    return 0;
}