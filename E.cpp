#include <iostream>
#include <map>
#include <vector>

//template <typename T>
typedef std::pair<int,int> mypair;

// class myLess{
// public:
//     bool operator()(const mypair& x1,const mypair& x2){
//         if(x1.first < x2.first) return true;
//         else if(x1.first == x2.first){
//             if(x1.second < x2.second) return true;
//             else return false;
//         }
//         else return false;
//     }
// };

// typedef std::pair<int,int> member;
typedef int id_member;
typedef int val_member;
std::map<int,int> memberList;
// std::vector<mypair> member_tmp;

int main(){
    int n;
    std::cin>>n;
    id_member tmp_i;val_member tmp_v;
    memberList.emplace(1000000000,1);
    for(int i = 0;i < n;++i){
        std::cin>>tmp_i>>tmp_v;
        auto it_low = memberList.lower_bound(tmp_v);
        // auto it_pre = --it_low;
        id_member id_next = it_low->second;
        val_member val_next = it_low->first;
        //大于tmp_v的第一个元素
        if(i == 0)
            std::cout<<tmp_i<<' '<<memberList.begin()->second<<std::endl;
        else{
            if(it_low != memberList.begin()){
                it_low--;
                val_member id_pre = it_low->second;
                id_member val_pre = it_low->first;
                if(abs(val_pre - tmp_v) == abs(val_next - tmp_v))
                    if(id_pre < id_next) std::cout<<tmp_i<<' '<<id_pre<<std::endl;
                    else std::cout<<tmp_i<<' '<<id_next<<std::endl;
                    //std::cout<<tmp_i<<' '<<id_pre<<std::endl;
                else    
                    if(abs(val_pre - tmp_v) > abs(val_next - tmp_v)) 
                        std::cout<<tmp_i<<' '<<id_next<<std::endl;
                    else std::cout<<tmp_i<<' '<<id_pre<<std::endl;      
            }
            else std::cout<<tmp_i<<' '<<it_low->second<<std::endl;
        }
        if(memberList.find(tmp_v) != memberList.end()){
            if(memberList[tmp_v] > tmp_i)
                memberList[tmp_v] = tmp_i;
        }        
        else memberList.emplace(tmp_v,tmp_i);    
    }
    return 0;
}