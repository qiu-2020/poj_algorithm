#include <iostream>
using namespace std;

class Base {
public:
   virtual Base& fun() { cout << "base fun" << endl; return *this; }
   virtual Base& foo() { cout << "base foo" << endl; return *this; }
};

class Derived: public Base {
public:
   Base& fun() { cout << "derived fun" << endl; return *this; }
   Base& foo() { cout << "derived foo" << endl; return *this; }
};

Base& foo();
Base& fun();



int main() {
   foo().fun().foo();
   // derived foo
   // derived fun
   // derived foo
   fun().foo().fun();
    // base fun
    //base foo
    //base fun
   return 0;
}