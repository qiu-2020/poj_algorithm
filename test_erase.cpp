#include <iostream>
#include <set>

int main(){
    std::set<int> s;
    for(int i = 0;i < 100;++i){
        s.emplace(i);
    }
    for(std::set<int>::iterator it = s.begin();it != s.end();it++){
        if(*it % 2 == 1) s.erase(it);
    }
    std::cout<<*s.begin()<<std::endl;
    return 0;
}