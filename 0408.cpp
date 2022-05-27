#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// 在此处补充你的代码

}
int main() {
  int x, y, t;
  unsigned int n, m;
  cin >> t;
  while (t--) { 
    cin >> n >> m >> x >> y;
    cout << calc(n, m, x, y) << endl;
  }
  return 0;
}

//00000000000000000000000000000000
//                           11111
//              111 111000000011111
//                  111111100000

//              111111111111111111