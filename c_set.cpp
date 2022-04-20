#include <iostream>
#include <string>
#include <set>
#include <map>

int main(){
    int n;
    std::cin>>n;
    std::map<int,int> mySet;
    // first int indicate integer，second indicate times
    std::set<int> flag;
    for(int i = 0;i < n;++i){
        std::string command;
        std::cin>>command;
        int x;
        if(command == "add"){
            std::cin>>x;
            auto it = mySet.find(x);
            if(it != mySet.end())
                it->second++;
            else{
                mySet.emplace(x,1);
                // flag.emplace(x);
            } 
            std::cout<<mySet[x]<<std::endl;   
        }
        else if(command == "del"){
            std::cin>>x;
            int num = 0;
            auto it = mySet.find(x);
            if(it != mySet.end()){
                num = it->second;
                it->second = 0;
            }
            std::cout<<num<<std::endl;
        }
        else if(command == "ask"){
            std::cin>>x;
            auto it = mySet.find(x);
            if(it != mySet.end()){
                std::cout<<1<<' '<<it->second<<std::endl;
            }
            else std::cout<<0<<' '<<0<<std::endl;
        }
    }


    return 0;
}