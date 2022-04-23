#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while(t--) {
		for(int i = 0;i < 12; ++i)
			cin >> a[i];
// 在此处补充你的代码
        set<int,less<int>> b{a[12]};
        typedef std::ostream_iterator<int>(std::cout,' ') c;
        std::copy(b.begin(), b.end(), c);
		cout << endl;

	}
	return 0;
}