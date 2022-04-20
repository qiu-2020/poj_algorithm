#include <iostream>
#include <set>

template<typename T>
class A{
private:
    T _n;
public:
    A(T n):_n(n){}
    friend bool operator<(const A& a,const A& b){
        return a._n < b._n;
    }        
    friend std::ostream& operator<<(std::ostream& os,const A& a){
        os<<a._n;
        return os;
    }
    friend class myGreater;
};

template <typename T>
class myGreater{
public:
    bool operator()(const A<T>& a,const A<T>& b){
        return a._n % 10 > b._n % 10;
    }    
};

std::multiset<A<double>> set1;
std::multiset<A<int>,myGreater<A<int>>> set2;

int main(){
    A<double> d_arr[4] = {1.0,2.0,3.3,4.4};
    set1.insert(d_arr,d_arr + 4);
    A<int> i_arr[5] = {33,123124,86589,1230,1};
    set2.insert(i_arr,i_arr + 5);
    set2.emplace(999);
    std::cout<<"hello"<<std::endl;
    return 0;
}