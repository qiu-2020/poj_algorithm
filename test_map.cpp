#include <iostream>
#include <map>

int main(){
    std::map<int,int> m;
    m = {{1,1},{3,3},{5,5}};
    // auto it_lower = m.lower_bound(2);
    // auto it_up = m.upper_bound(4);
    // std::cout<<it_lower->first<<' '<<it_up->first<<std::endl;
    // it_lower--;
    // std::cout<<it_lower->first<<' '<<it_up->first<<std::endl;
    auto it = m.begin();
    it--;
    if(it == m.begin())
        std::cout<<'y'<<std::endl;
    else std::cout<<'n'<<std::endl;    
    return 0;
}