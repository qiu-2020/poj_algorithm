#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
vector<int> numbers;
int main(){ 
    auto f = [] (int d){
        return [d] (int x){
            return x % d == 0;
        };
    }
// 在此处补充你的代码
;
    int n, x, d;
    while(cin >> n) {
        numbers.clear();
        for (int i = 1;i <= n;i ++){
            cin >> x;
            numbers.push_back(x);
        }
        cin >> d;
        cout << count_if(numbers.begin(), numbers.end(), f(d)) << endl;
    }
    return 0;
}

//6
// 1997 12 2 2000 5 18
// 3
// 6
// 16 12 97 18 14 23
// 2

//2
//4
