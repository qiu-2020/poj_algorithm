#include <iostream>
#include <list>


int main(){
    int m,n,count = 1;
    std::cin>>n>>m;
    std::list<int> lst;
    for(int i = 1;i <= n;++i)
        lst.push_back(i);
    std::list<int>::iterator it = lst.begin();
    // int count = 1;    
    while(lst.size() > 1){
        while(it != lst.end()){
            if(count % m == 0){
                it = lst.erase(it);
                count = 1;
            }
            else{
                count++;
                it++;
            }    
        }
        if(it == lst.end()) 
            it = lst.begin();
    }
    std::cout<<lst.front()<<std::endl;

    return 0;
}