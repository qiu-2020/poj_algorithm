#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;
// 在此处补充你的代码

template <typename T>
class CMyClass{
    T* _ptr_arr;
    int _size;
public:
    CMyClass(T* ptr,int s):_size(s){
        _ptr_arr = new T [s];
        memcpy(_ptr_arr,ptr,s * sizeof(ptr[0]));
    }
    T& operator[](const int& i){
        return _ptr_arr[i];
    }
};


int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}