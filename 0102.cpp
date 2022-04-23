#include<bits/stdc++.h>
using namespace std;

class Food {
public:
// 在此处补充你的代码
    void Buy(){cout<<"Buy Nothing"<<endl;}
    virtual void Pay(){}
};

class Meat : public Food {
public:
	void Buy() { cout << "Buy Meat" << endl; }
	virtual void Pay() { cout << "Pay Meat" << endl; }
};

class Beef : public Meat {
public:
	void Buy() { cout << "Buy Beef" << endl; }
	void Pay() { cout << "Pay Beef" << endl; }
};
int main() {
	Beef bf;
	Meat* pmt = &bf;
	Food* pfd = &bf;

	pfd->Buy();
    //Buy Nothing
	pfd->Pay();
    //Pay Beef
	pmt->Buy();
    //Buy Meat
	pmt->Pay();
    //Pay Beef
	return 0;
}