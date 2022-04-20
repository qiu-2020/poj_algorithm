#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
// 在此处补充你的代码
    int operator*(const int& n2){
        return num * n2;
    }
    friend bool operator==(const int& n1,const Number& n2){
        return n1 == n2.num;
    }
    friend ostream& operator<<(ostream& os,const Number& n){    
        os<<n.num;
        return os;
    }
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}