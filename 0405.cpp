#include<iostream>
#include<vector>
using namespace std;
class A{
// 在此处补充你的代码
static int presum;
    int _n;
public:
    A(int n):_n(n){}
    void output(){
        presum += _n;
        std::cout<<presum<<std::endl;
    }
};
int A::presum=0;
int main(){
  int n;cin>>n;
  vector<A*> p;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    p.push_back(new A(x));
  }
  for(int i=0;i<n;i++){
    p[i]->output();
  }
  return 0;
}