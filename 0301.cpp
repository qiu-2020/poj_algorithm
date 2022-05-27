#include <iostream>
using namespace std;

class Counter {


private:
	static int nGlobalNumber;
	int nLocalNumber;
public:
// 在此处补充你的代码

Counter(){
    nGlobalNumber++;
    nLocalNumber = 1;
}
Counter(int n):nLocalNumber(n){
    nGlobalNumber++;
}
Counter(const Counter& c):nLocalNumber(c.nLocalNumber){
    nGlobalNumber++;
}
~Counter(){
    nGlobalNumber--;
}

void add(int n) { nLocalNumber += n; }

void PrintLocalNumber(){
		cout << nLocalNumber << endl;
}
static void PrintGlobalNumber() {
		cout << nGlobalNumber << endl;
}

};
int Counter::nGlobalNumber = 0;

int main()
{
	Counter::PrintGlobalNumber();
    //0
	Counter b1, b2;
	Counter::PrintGlobalNumber();
    //2
	b1.PrintLocalNumber();
    //1
	b2.add(10);
	b2.PrintLocalNumber();
    //11
	Counter* b3 = new Counter(7);
	b3->PrintLocalNumber();
    //7
	Counter b4 = b2;
	b4.PrintLocalNumber();
    //11
	Counter::PrintGlobalNumber();
    //4
	if (b3 != NULL)
	{
		delete b3;
		b3 = NULL;
	}
	Counter::PrintGlobalNumber();
    //3

	return 0;
}