#include <iostream>
#include <vector>
#include <algorithm>

void file_tree(std::string root,int level){
    std::vector<std::string> this_dir;
    std::string str_tmp;
    for(int i = 0;i < level;++i)
        std::cout<<"|     ";
    std::cout<<root<<std::endl;   
    while(std::cin>>str_tmp){
        if(str_tmp[0] == 'f')
            this_dir.push_back(str_tmp);
        else if(str_tmp[0] == 'd'){
            file_tree(str_tmp,level + 1);
        }
        else if(str_tmp[0] == ']' || str_tmp[0] == '*'){
            std::sort(this_dir.begin(),this_dir.end());
            for(std::vector<std::string>::iterator it = this_dir.begin();it != this_dir.end();++it){
                for(int j = 0;j < level;++j)
                    std::cout<<"|     ";
                std::cout<<*it<<std::endl;
            }
            return;
        }
    }
}

int main(){
    int i = 1;
    while(std::cin.peek() != '#'){
//        std::cin.get();
        std::cout<<"DATA SET "<<i<<':'<<std::endl;
        file_tree("ROOT",0);
        std::cout<<std::endl;
        i++;
        std::cin.clear();
        std::cin.ignore();
    }


    return 0;
}