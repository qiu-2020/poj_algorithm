#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
    string ans;
    while(x != 0){
        ans = char(x % 2 + '0') + ans;
        x /= 2;
    }
    while(ans.length() < 31){
        ans = '0' + ans;
    }
    return ans;
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
//0000000000000000000000000000001
//00000000000000000000000000000001