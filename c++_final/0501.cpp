#include <iostream>
using namespace std;
int getByte(int x, int i){
    long mask = 0x11111111;
    long ans = x & (mask << i * 8);
    ans = ans >> i * 8;
    return ans;
// 在此处补充你的代码;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x, i;
        cin >> x >> i;
        cout << getByte(x, i) << endl;
    }
    return 0;
}