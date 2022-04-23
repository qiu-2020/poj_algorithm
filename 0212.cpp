#include <iostream>
using namespace std;
class A
{
	static int num;
public:
	A(){num+=1;}
	void func()
	{
		cout<< num <<endl;
	}
// 在此处补充你的代码
    void func() const{
        num--;
        cout<< num <<endl;
    }
};

int A::num=1;

int main()
{
	A a1;
	const A a2 = a1;
	A & a3 = a1;
	const A & a4 = a1;

	a1.func();
    //2
	a2.func();
    //1
	a3.func();
    //1
	a4.func();
    //0
	return 0;
}