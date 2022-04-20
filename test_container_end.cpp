#include <iostream>
#include <set>
    std::set<int> s{1,2,3,4,45,9};
int main(){
    s.clear();
    // std::set<int>::iterator it = s.end();
    // std::cout<<*it<<std::endl;
    for(auto i : s)
        std::cout<<i<<' ';
    std::cout<<std::endl;    
    return 0;
}