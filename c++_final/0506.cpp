#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码

template <typename T>
class MyFunc{
private:
    T& _ans;
    T tmp;
    int _num;
public:
    MyFunc(int& n,T& a):_num(n),_ans(a){tmp = T();}
    void operator()(T& a){
        tmp += a;
        T this_ans = T();
        for(int i = 0;i < _num;++i)
            this_ans += tmp;
        _ans = this_ans;
    }    
};

int main(){
    vector<int> v1;
    vector<string> v2;
    int N, val, num_repeat,result_int=0;
    string str,result_str="";
    cin>>N;
    cin>>num_repeat;
    for(int i=0;i<N;++i){
        cin>>val;
        v1.push_back(val);
    }
    // ab
    for_each(v1.begin(),v1.end(),MyFunc<int>(num_repeat,result_int));
    for(int i=0;i<N;++i){
        cin>>str;
        v2.push_back(str);
    }
    for_each(v2.begin(),v2.end(),MyFunc<string>(num_repeat,result_str));
    cout<<result_int<<endl;
    cout<<"--------------"<<endl;
    cout<<result_str<<endl;
}