#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        vector<vector<int>> g(n,vector<int>(n,0)); 
        vector<vector<int>> f(k,vector<int>(n,0));
        g[0][0] = pages[0];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if(i > j) g[i][j] = 0x3fffffff;
                else if(i == j) g[i][j] = pages[i];
                else g[i][j] = g[i][j - 1] + pages[j];
            }
        }
        for(int i = 0;i < n;++i)
            f[0][i] = g[0][i];
        for(int i = 1;i < k;++i){
            for(int j = 0;j < n;++j){
                
            }
        }
    }
};

int main(){



    return 0;
}