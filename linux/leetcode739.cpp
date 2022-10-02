#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i = n - 1;i >= 0;--i){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();   
            if(st.empty())
                ans[i] = 0;
            else         
                ans[i] = st.top() - i;
            st.push(i);
        }        
        return ans;
    }

};

int main(){
    vector<int> v1{73,74,75,71,69,72,76,73},v2{30,40,50,60},v3{30,60,90};
    Solution s;
    int size = s.dailyTemperatures(v1).size();
    for(int i = 0;i < size;++i)
        std::cout<<s.dailyTemperatures(v1)[i]<<std::endl;
    // std::cout<<s.dailyTemperatures(v2)<<std::endl;



    return 0;
}