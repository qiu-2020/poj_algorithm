#include <iostream>
#include <vector>

template <typename T>
class mySet{
private:
    std::vector<T> _s;
public:
    typename std::vector<T>::iterator first_element(void){
        return _s.begin();
    }
    void add_element(const T& x){
        _s.push_back(x);
    }
};

template<typename T,typename T_key,typename T_value>
class mymySet : public mySet<T>{
private:
    std::pair<T_key,T_value> _p;
public:
    void setP(T_key k,T_value v){
        _p.first = k;
        _p.second = v;
    }
    void change_first(const T& x){
        typename std::vector<T>::iterator it = first_element();
        *it = x;
    }
};

int main(){
    mymySet<int,std::string,std::string> mms;
    mms.setP("nihao","qiu");

    mms.add_element(99);
    std::cout<<*(mms.first_element())<<std::endl;
    mms.change_first(9999);
    std::cout<<*(mms.first_element())<<std::endl;

    return 0;
}