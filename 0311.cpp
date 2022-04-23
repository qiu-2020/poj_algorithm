#include <iostream>
#include <set>

// typedef int id;
// typedef int pri;

class comparison{
public:
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2){
        if(p1.first > p2.first) return true;
        else if(p1.first == p2.first){
            if(p1.second < p2.second) return true;
            else return false;
        }
        else return false;

    }
}; 

std::multiset<std::pair<int,int>,comparison> s[3];

int main(){
    int T,t;
    std::string command;
    std::cin>>T;
    for(int i = 0;i < T;++i){
        std::cin>>t;
        int count = 0;
        for(int j = 0;j < t;++j){
            std::cin>>command;
            if(command == "IN"){
                count++;
                int para1,para2;
                std::cin>>para1>>para2;
                s[para1 - 1].emplace(std::make_pair(para2,count));
            }
            else if(command == "OUT"){
                int para1;
                std::cin>>para1;
                if(s[para1 - 1].empty())                                     std::cout<<"EMPTY"<<std::endl;
                else{
                    std::cout<<s[para1 - 1].begin()->second<<std::endl;
                    s[para1 - 1].erase(s[para1 - 1].begin());
                }
            }
        }
    }



    return 0;
}