#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <set>
#include <cstdio>
using namespace std;
// 在此处补充你的代码

// template<typename T>
// set<T> s;

template <typename T>
class MySet : public set<T>{
public:    
    void erase(T* ptr_s,T* ptr_e){
        auto it_s = find(*ptr_s);
        auto it_e = find(*ptr_e);
        erase(it_s,it_e);
    }
    // void erase(int a,int b)
};


struct A {
	int n;
	A(int i):n(i) { }
	operator int() {
		return n;
	}
	bool operator >(const A & a) const {
		return n > a.n;
	}
};
template <class IT>
void print(IT s,IT e)
{	
	for(; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}
int main()
{
	MySet<int> mst;
	for (int i = 0;i < 10; ++i)
		mst.insert(i);
	print(mst.begin(),mst.end());
	int a[] = {1,2,3,4};
	mst.erase(a,a+3);
	print(mst.begin(),mst.end());
	
	A b[] = {{7},{8}};
	mst.erase(b,b+2);
    //MySet<int>
	print(mst.begin(),mst.end());	
	mst.erase(mst.find(6));
	print(mst.begin(),mst.end());
	for(int i = 0;i < 1000000; ++i)
		mst.insert(i);
	for(int i = 0; i < 1000000 - 10; ++i) 
		mst.erase(mst.find(i));
	int n;
	cin >> n;
	MySet<A> msta;
	
	for(int i = 0;i < n; ++i) {
		string cmd;
		int n;
		cin >> cmd >> n;
		if( cmd == "ADD") 
			msta.insert(A(n));
		else {
			if (msta.find(A(n))!= msta.end())
				cout << "YES"  <<endl; 
			else
				cout << "NO" <<endl;
		}
	}
	return 0;
}