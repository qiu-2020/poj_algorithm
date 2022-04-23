#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
// 在此处补充你的代码
private:
    multiset<int,greater<int>> _q;
    int _k;
public:
    MyQueue(int k):_k(k){}
    friend istream& operator>>(istream& is,MyQueue& q){
        int tmp;
        is>>tmp;
        q._q.emplace(tmp);
        return is; 
    }
    friend ostream& operator<<(ostream& os,MyQueue& q){
        int count = 0;
        auto it = q._q.begin();

        while(it != q._q.end()){
            if(*it % 2 == 0){
                os<<*it<<' ';
                count++;
                if(count == q._k) return os;
            }
            it++;
        }
    
    }
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
	return 0; 
}