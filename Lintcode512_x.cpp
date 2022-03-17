#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        
    }
};

int main(){
    string input_1("121034"),input_2("192611");
    Solution s;
    cout<<s.numDecodings(input_1)<<endl;
    cout<<s.numDecodings(input_2)<<endl;

    return 0;
}