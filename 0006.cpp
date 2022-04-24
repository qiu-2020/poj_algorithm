#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码

class Rectangle{
public:    
    int _a,_b;   
    Rectangle(int a,int b):_a(a),_b(b){}
    friend ostream& operator<<(ostream& os,const Rectangle& r){
        os<<r._a * r._b<<' '<<r._a * 2 + r._b * 2;
        return os;
    }
    friend bool operator<(const Rectangle& r1,const Rectangle& r2){
        if(r1._a * r1._b > r2._a * r2._b) return true;
        else if(r1._a * r1._b == r2._a * r2._b){
            if(r1._a + r1._b > r2._a + r2._b) return true;
            else return true;
        }
        else return false;
    }
    bool operator<(const Rectangle& r){
        if(_a * _b > r._a * r._b) return true;
        else if(_a * _b == r._a * r._b){
            if(_a + _b > r._a + r._b) return true;
            else return true;
        }
        else return false;
    }
};

struct Comp{
public:
    bool operator()(const Rectangle& r1,const Rectangle& r2){
        if(r1._a + r1._b < r2._a + r2._b) return true;
        else if(r1._a + r1._b == r2._a + r2._b){
            if(r1._a * r1._b < r2._a * r2._b) return true;
            else return false;
        }
        else return false;
    }
};


int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}