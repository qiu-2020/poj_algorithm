#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<bool> f(n + 1,false);
        f[1] = true;f[2] = true;
        if(n < 2) return f[n];
        for(int i = 3;i <= n;++i){
            if(f[i - 1] == true && f[i - 2] == true)
                //对手都能赢
                f[i] = false;
            else f[i] = true;    
        }
        return f[n];
    }
};

int main(){
    int n;
    Solution s;
    std::cin>>n;
    if(s.firstWillWin(n))
        std::cout<<"true"<<std::endl;
    else    
        std::cout<<"false"<<std::endl;


    return 0;
}