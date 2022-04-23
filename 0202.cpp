#include <iostream>
using namespace std;
template <class T>
class Add{
public:
// 在此处补充你的代码
    T _x;
    Add(T x):_x(x){}
    T operator()(const T& x,const T& y){
        return x + y - _x;
    }

};

int main(){
	double f;
	int n;
	while( cin >> f >> n) {
		
		Add<double> a1(f);
		Add<int> a2(n);
		double x,y;
		int p,q;
		cin >> x >> y >> p >> q;
		cout << a1(x, y) << endl;
		cout << a2(p, q) << endl;
	}
	return 0;
}