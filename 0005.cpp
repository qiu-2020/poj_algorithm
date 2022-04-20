#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码

template<typename T1,int size>
class A{
public:    
    // A<T1,size>()
    T1* arr;
    A<T1,size>(T1 ptr_arr[]){
        arr = new T1 [size];
        for(int i = 0;i < size;++i)
            arr[i] = ptr_arr[i];
    }
    void operator=(T1 ptr_arr[]){
        if(arr != nullptr)
            delete [] arr; 
        arr = new T1 [size];
        for(int i = 0;i < size;++i)
            arr[i] = ptr_arr[i];
    }
    T1 operator[](const int& i){
        return arr[i];
    }
    T1 sum(void){
        T1 ans = arr[0];
        for(int i = 1;i < size;++i)
            ans += arr[i];
        return ans;    
    }
};

int main() {
	
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 	
	
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];
	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];
	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}