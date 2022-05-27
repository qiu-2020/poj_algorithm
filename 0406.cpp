#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
// 在此处补充你的代码
    Midterm(int v = 0):val(v){}
    friend ostream& operator<<(ostream& os,const Midterm& m){
        os<<m.val;
        return os;
    }
    Midterm operator+(const int& x){
        return Midterm(x + val);
    }
    Midterm& operator++(int){
        // Midterm tmp(val);
        val++;
        return *this;
    }
    Midterm& operator-=(const int& x){
        val -= x;
        return *this;
    }
    operator int(){
        return val;
    }
};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  //0
  cout << a + 2021 << endl;
  //2021
  Midterm b(1000);
  //
  cout << b ++ << endl;
  //1001 
  ((b-=10)-=20)-=30;
  //942
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  //255
  return 0;
}