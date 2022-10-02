#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i = 0;i < n;++i){
            if(asteroids[i] < 0){
                while(!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top())
                    st.pop();
                if(!st.empty() && st.top() == abs(asteroids[i]))
                    st.pop();    
                else if(st.empty() || st.top() < 0)    
                    st.push(asteroids[i]);    
            }
            else st.push(asteroids[i]);   
        }
        vector<int> ans;
        while(!st.empty()){
            ans.insert(ans.begin(),st.top());
            st.pop();
        }    
        return ans;
    }
};

int main(){
    vector<int> a[3]{{-2,-2,1,-2},{8,-8},{10,2,-5}};
    Solution s;
    for(int i = 0;i < 3;++i){
        auto ans = s.asteroidCollision(a[i]);
        for(int i = ans.size() - 1;i >= 0;--i)
            std::cout<<ans[i]<<' ';
        std::cout<<std::endl;    
    }
    



    return 0;
}