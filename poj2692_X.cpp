#include <iostream>
#include <cstring>

char left[3][5],right[3][5],ans[3][5];

bool isCounterfeitCoin(char x,bool islight){
//islight == true 代表假设x是清的
    bool flag = false;
    for(int i = 0;i < 3;++i){
  
        if(strchr(left[i],x)){
            flag = true;//出现过
            if(ans[i][0] == 'e') return false;
            if(!(islight && ans[i][0] == 'd')) return false;
            if(!(!islight && ans[i][0] == 'u')) return false;
        }
        else if(strchr(right[i],x)){
            flag = true; //出现过
            if(ans[i][0] == 'e') return false;
            if(!(islight && ans[i][0] == 'u')) return false;
            if(!(!islight && ans[i][0] == 'd')) return false;
        }
        else continue;  
    }
    return true;
    // if(!flag) return true;
    // else return false;
}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < 3;++j)
            std::cin>>left[j]>>right[j]>>ans[j];
        for(char t = 'A';t <= 'L';++t){
            if(isCounterfeitCoin(t,true))
                std::cout<<t<<" is the counter coin and it is light"<<std::endl;
            if(isCounterfeitCoin(t,false))
                std::cout<<t<<" is the counter coin and it is heavy"<<std::endl;    
            }    
    }

    return 0;
}