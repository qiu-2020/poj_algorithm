#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码

class Fib{
private:
    int _n;
    int _pre,_num;
public:
    Fib(int n):_n(n){
        _pre = 0;
        _num = 1;
        for(int i = 2;i <= n;++i){
            int tmp = _pre;
            _pre = _num;
            _num = tmp + _num;
        }
    }
    void operator++(){
        int tmp = _pre;
        _pre = _num;
        _num = tmp + _num;
        _n++;
    }  
    int operator*(){
        return _num;
    }  
    bool operator!=(const Fib& x){
        if(_n != x._n) return true;
        else
            if(_num == x._num) return false;
            else return true;
    }

};

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}