#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int i = 1;

void print_dir(std::string,int);

void file_system(void){
    while(std::cin.peek() != '#'){
        std::cout<<"DATA SET "<<i<<":"<<std::endl;
        print_dir("ROOT",0);
        std::cin.clear();
        std::cin.ignore();
    }
    return;
}

void print_dir(std::string dname,int level){
    std::string str;
    for(int i = 0;i < level;++i)
        std::cout<<"|     ";
    std::cout<<dname<<std::endl;
    std::cin>>str;
    std::vector<std::string> v;
    while(str != "*"){
        if(str[0] == 'f')
            v.push_back(str);    
        else if(str[0] == 'd'){
            print_dir(str,level + 1);
        }
        else if(str[0] == ']'){
            std::sort(v.begin(),v.end());
            for(auto it = v.begin();it != v.end();++it){
                for(int i = 0;i < level;++i){
                    std::cout<<"|     ";
                }
                std::cout<<*it<<std::endl;
            }
            return;
        }   
        std::cin>>str;  
    }  
    std::sort(v.begin(),v.end());
    for(auto it = v.begin();it != v.end();++it){
        for(int i = 0;i < level;++i){
            std::cout<<"|     ";
        }
        std::cout<<*it<<std::endl;
    }  
    i++;
    std::cout<<std::endl;

    return;
    // std::cin>>str;
    // std::vector<std::string> v;
    
    // if(str[0] == 'f'){
    //     v.push_back(str)
    //     print_dir();
    //     std::cout
    // }
}

int main(){
    file_system();


    return 0;
}