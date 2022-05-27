#include <iostream>
#include <string>
#include <set>
using namespace std;

class Counter{
    int cnt;
public:
    Counter():cnt(0){}
    virtual void push(void*) = 0;
    virtual string name() = 0;
    void inc(){
        ++cnt;
    }
    int number(){
        return cnt;
    }
};

template<class T>
class TCounter: public Counter{
// 在此处补充你的代码
    string _name;
    set<T> _s;
public:
    TCounter(string str):_name(str){}
    virtual void push(void* t_data){
    //参数类型不一致函数重载，本质不是一个函数,必须和纯虚函数生命完全一致！
        if(_s.find(*((T*)t_data)) == _s.end()){    
            _s.emplace(*((T*)t_data));
            inc();
        }    
    }
    virtual string name(){
        return _name;
    }
};

Counter* build_counter(string name){
    if (name == "int") return new TCounter<int>("int");
    else return new TCounter<string>("string");
}



int main(){
    int n, m;
    cin >> n >> m;
    Counter *a = build_counter("int"), *b = build_counter("string");
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a->push(&x);
    }
    for (int i = 0; i < m; ++i){
        string x;
        cin >> x;
        b->push(&x);
    }
    cout << a->name() << ": " << a->number() << endl;
    cout << b->name() << ": " << b->number();
    return 0;
}