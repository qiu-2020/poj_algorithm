#include <iostream>
#include <map>
#include <string>


std::map<std::string,std::pair<int,int>> meals;

int main(){
    int n,m;
    std::cin>>n>>m;
    std::string str1;
    int price,num;
    for(int i = 0;i < m;++i){
        std::cin>>str1>>price>>num;
        meals.emplace(std::make_pair(str1,std::make_pair(price,num)));
    }
    int ans = 0;
    std::string str[3];
    for(int i = 0;i < n;++i){
        for(int j = 0;j < 3;++j){
            std::cin>>str[j];
            if(meals[str[j]].second > 0){
                ans += meals[str[j]].first;
                meals[str[j]].second--; 
            }    
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}