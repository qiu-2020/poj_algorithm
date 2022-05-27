#include <iostream>
using namespace std;

class myobject {
public:
// 在此处补充你的代码
    static int counter;
    
};

class producer : public myobject {
public:
	static int counter;
	virtual void work() {
		counter = counter + 5;
		std::cout<<counter;
	}
};

int myobject::counter = 0;

int main(){
	producer *pro = new producer();
	myobject *con = new myobject();
	pro->work(); pro->work(); cout << endl;
    //5             10
	con->work(); con->work(); con->work(); cout << endl;
    //6             2            2
	pro->work(); cout << endl;
    //7 
	con->work(); con->work(); cout << endl;
    // 3              3
}