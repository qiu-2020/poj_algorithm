#include <iostream> 
using namespace std;

class A { 
	public: 
		virtual void Fun() { 
			cout << "A::Fun" << endl; 
		}; 
		virtual void Do() { 
			cout << "A::Do" << endl; 
		} 
};
// 在此处补充你的代码

class B : public A{
    public:
        void Fun(){
            cout << "B::Fun" << endl; 
        }
        virtual void Do(){
            cout << "B::Do" << endl;
        }
};

class C: public B{
    public:
        void Fun(){
            cout << "C::Fun" << endl; 
        }
        void Do(){
            cout << "C::Do" << endl;
        }
};

void Call1(A& p)
{ 
	p.Fun(); 
	p.Do(); 
} 

void Call2(B p) {
	p.Fun();
	p.Do();
}



int main() { 
	C c;
	B b;
	Call1(b);
    //A::Fun
    //B::Do
	Call1(c); 
    //C::Fun
    //C::Do
	Call2(c);
    //A::Fun
    //B::Do
	return 0;
}