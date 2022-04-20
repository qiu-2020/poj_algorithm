#include <iostream>
#include <vector>
#include <set>


typedef std::pair<int,int> member;
std::set<member> memberList;
typedef std::set<member>::iterator it_set;
// std::vector<member> memberList;
// typedef std::vector<member>::iterator it_vec; 


int main(){
    int n;
    std::cin>>n;
    member facer(1000000000,1);
    memberList.emplace(facer);
    int key,val;
    for(int i = 0; i < n;++i){
        std::cin>>key>>val;
        member tmp(val,key);
        auto it = memberList.begin();
        for(;it != memberList.end();++it){
            if(it->first >= tmp.first)
                break;
        }
        // if(memberList.size() == 1)
        //     std::cout<<tmp.second<<' '<<memberList.begin()->second;
        // else{
        //MAX 999 1 1000  | 998
        if(i == 0){
            std::cout<<tmp.second<<' '<<memberList.begin()->second<<std::endl;
        }
        else{    
            if(it == memberList.begin())
                std::cout<<tmp.second<<' '<<it->second<<std::endl;
            else if(it == memberList.end()){
                std::cout<<tmp.second<<' '<<(--it)->second<<std::endl;
            }    
            else{    
                auto it_d = it->first,it_n = it->second;
                auto it_pre = --it;
                if(abs(it_pre->first - tmp.first) == abs(it_d - tmp.first))
                    std::cout<<tmp.second<<' '<<it_pre->second<<std::endl;
                else{
                    if(abs(it_pre->first - tmp.first) > abs(it_d - tmp.first))
                        std::cout<<tmp.second<<' '<<it_n<<std::endl;
                    else
                        std::cout<<tmp.second<<' '<<it_pre->second<<std::endl;    
                    // }    
                }
            }
        }    
        memberList.emplace(tmp);
    }

    return 0;
}

