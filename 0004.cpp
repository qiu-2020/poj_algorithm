#include <iostream>
using namespace std;

class A {
public:
// 在此处补充你的代码
    int _a;
    A(int a):_a(a){}
    friend ostream& operator<<(ostream& os,const A& a){
        os<<a._a;
        return os;
    }
    A& operator+=(const A& a){
        _a += a._a;
        return *this;
    }
    A& operator-=(const A& a){
        _a -= a._a;
        return *this;
    }
    A& operator-=(int a){
        _a -= a;
        return *this;
    }
    // int getValue(void){
    //     return _a;
    // }
    A& getValue(void){
        return *this;
    }
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}