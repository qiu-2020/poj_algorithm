#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 在此处补充你的代码

// typedef typename vector<int>::iterator it_int;
// typedef typename vector<string>::iterator it_string;

// template <typename T>
// class less<T>;

// template <typename T>
// class less{
// public:
// 	less(){}
//     bool operator()(const T& x,const T& m){
// 		if(x < m) return true;
// 		else return false;
// 	}
// };

template <typename Init,typename T,typename OP>
Init FindFirstLess(Init s,Init e,T m,OP c_f){
	auto it = s;
	for(;it != e;++it)
		if(c_f(*it,m)) return it;
	return it;
}


int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n ;
		string type; 
		cin >> n >> type;
		vector<int> vi;
		vector<string> vs;
		if( type == "N") {
			int a,m;
			for(int i = 0;i < n  - 1; ++i) {
				
				cin >> a;
				vi.push_back(a);
			}
			cin >> m;
			vector<int>::iterator p = FindFirstLess(vi.begin(),vi.end(),m,less<int>());
			if( p!= vi.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl; 
				
		}
		else {
			string a,m;
			for(int i = 0;i < n - 1; ++i) {
				cin >> a;
				vs.push_back(a);
			}
			cin >> m;
			vector<string>::iterator p = FindFirstLess(vs.begin(),vs.end(),m,less<string>());
			if( p!= vs.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl; 
		
		}
	}
    return 0;
}