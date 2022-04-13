#include <iostream>
#include <set>

std::set<int >s;
int main(){
    for(int i = 0;i < 50;++i)
        s.emplace(i);
    for(std::set<int>::iterator it = s.begin();it != s.end();){
        if(*it % 3 == 1){
            std::cout<<*it<<std::endl;
            s.erase(it++);
        }
        else it++;    
    }
    std::cout<<"hello"<<std::endl;
    return 0;
}