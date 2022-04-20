#include <iostream>
#include <set>
#include <map>



int main(){
    int c;
    std::cin>>c;
    typedef std::map<int,std::multiset<int>> map_List;
    map_List myList;
    int n,num,n1,n2;
    for(int i = 0;i < c;++i){
        std::string command;
        std::cin>>command;
        if(command == "new"){
            std::cin>>n;
            std::multiset<int> s;
            myList.emplace(n,s);
        }
        else if(command == "add"){
            std::cin>>n>>num;
            myList[n].emplace(num);
        }
        else if(command == "out"){
            std::cin>>num;
            for(auto it:myList[num])
                std::cout<<it<<' ';
            std::cout<<std::endl;    
        }
        else if(command == "merge"){
            std::cin>>n1>>n2;
            bool isequal = true;
            for(auto i : myList[n1])
                if(myList[n2].find(i) == myList[n2].end()){
                    isequal = false;
                    break;
                }
            if(isequal)    
                for(auto i : myList[n2])
                    if(myList[n1].find(i) == myList[n1].end()){
                        isequal = false;
                        break;
                    }
            if(!isequal){
                for(auto i : myList[n2])
                    myList[n1].emplace(i);
                myList[n2].clear();
            }        
        }
        else if(command == "unique"){
            std::cin>>n;
            // for(auto it = myList[n].begin();it != myList[n].end();){
            //     int it_data = *it; it++;
            //     if(it_data == *it && it != myList[n].end()) 
            //         it = myList[n].erase(it);       
            // }
            std::set<int> tmp;    
            for(auto i : myList[n]){
                tmp.emplace(i);
            }
            myList[n].clear();
            for(auto i : tmp)
                myList[n].emplace(i);
        }
    }

    return 0;
}