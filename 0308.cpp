#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
// 在此处补充你的代码

class A{
public:
    A(){
        std::cout<<"New A"<<std::endl;
    }        
    virtual  ~A(){
        std::cout<<"Delete A"<<std::endl;
    }
};

class B : public A{
public:
    B(){
        std::cout<<"New B"<<std::endl;
    }    
    ~B(){
        std::cout<<"Delete B"<<std::endl;
        // A::~A();
        // std::cout<<"Delete A"<<std::endl;
    }
};

int main(){
	int n;
	cin >> n;
    //3
	for (int i = 1; i<=n; i++) {
		int x;
		cin >> x;
        //1 0 1
		if (x == 0) {
			A *a = new A();
			delete a;
		}else {
			A *a = new B();
			delete a;
		}
	}
	return 0;	
}