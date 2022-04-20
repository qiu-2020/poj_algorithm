#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

template<typename T>
class sumPower{
    int _power;
public:
    sumPower(int p):_power(p){}
    T operator()(const T& init,const T& x){
        T ans = 1;
        for(int i = 1;i <= _power;++i)
            ans *= x;
        return ans + init;    
    }    
};


int main(){
    std::vector<int> v;
    for(int i = 1;i < 3;++i)
        v.push_back(i);
    // sumPower<int> s_p(4);
    std::cout<<std::accumulate(v.begin(),v.end(),0,sumPower<int>(3))<<std::endl;


    return 0;
}