#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// 在此处补充你的代码
    T _data;
public:
    container(T d):_data(d){}
    container(const container& c){
        _data = c._data;
    }    
    container operator+(const container& x){
        return container(_data + x._data + x._data);
    }
    container operator+(const T& x){
        return container(_data + x);
    }
    friend ostream& operator<<(ostream& os,const container& c){
        os<<c._data;
        return os;
    }
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}