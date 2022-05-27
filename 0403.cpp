#include <iostream>
using namespace std;
class Mammal {
public:
  Mammal() { cout << "Mammal constructor...\n"; }
  virtual ~Mammal() { cout << "Mammal destructor...\n"; }
  Mammal (const Mammal & rhs);
  virtual void Speak() const { cout << "Mammal speak!\n"; }
  virtual Mammal* Clone() { return new Mammal(*this); }
};
  
class Dog : public Mammal {
// 在此处补充你的代码
public:
    Dog();
    Dog(const Dog& d):Mammal(d){
        cout<<"Dog copy constructor...\n";
    }
    Dog* Clone() { return new Dog(*this); }
    ~Dog();
    void Speak() const;
};

Mammal::Mammal (const Mammal & rhs) {
  cout << "Mammal Copy Constructor...\n";
}
  
Dog::Dog(){ cout << "Dog constructor...\n"; }
Dog::~Dog(){ cout << "Dog destructor...\n"; }
void Dog::Speak()const { cout << "Woof!\n"; }

int main() {  
  Mammal* x=new Dog, *y=new Mammal;
  //Mammal constructor... Dog constructor...
  //Mammal constructor...    
  Mammal* x1=x->Clone(), *y1=y->Clone();
  //Mammal Copy Constructor...
  //Dog copy constructor...  Mammal Copy Constructor...
  x1->Speak(); y1->Speak();
  //Woof!  Mammal speak! 
  return 0;
}