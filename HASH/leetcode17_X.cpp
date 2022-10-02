#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static vector<string> ans;
        static map<char,string> m{make_pair<char,string>('2',"abc"),make_pair<char,string>('3',"def"),make_pair<char,string>('4',"ghi"),make_pair<char,string>('5',"jkl"),make_pair<char,string>('6',"mno"),make_pair<char,string>('7',"pqrs"),make_pair<char,string>('8',"tuv"),make_pair<char,string>('9',"wxyz")};

        if(digits == "") return ans;
        else{
            //string c = digits.substr(0,0);
            vector<string> tmp;
            if(ans.empty()){
                string str = m[digits[0]];
                for(int i = 0;i < str.size();++i)
                    ans.push_back(str.substr(i,i + 1));    
            }
            else{
                while(!ans.empty()){
                    auto it_str = ans.begin();
                    string str = *it_str;
                    ans.erase(it_str);
                    for(int i = 0;i < m[digits[0]].size();++i){
                        string t_str = str + m[digits[0]].substr(i,i);
                        tmp.push_back(t_str);
                    }
                }
                auto it = tmp.begin();
                while(it != tmp.end()){
                    ans.push_back(*it);
                    it = tmp.erase(it);
                }
            }
            letterCombinations(digits.substr(1));
        }
    }
};

int main(){
    Solution s;
    string input[3]{"23","","2"};
    for(int i = 0;i < 3;++i){
        vector<string> ans = s.letterCombinations(input[i]);
        for(auto it = ans.begin();it != ans.end();++it)
            cout<<*it<<' ';
        cout<<endl;    
    }

    return 0;
}