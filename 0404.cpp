#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
// 在此处补充你的代码
class cmp{
    // char _d = 'a';
public:
    // void operator(const T& a,const int& b){
    //     cout<<_d<<std::endl;
    //     _d++;
    // }
    

};

int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}