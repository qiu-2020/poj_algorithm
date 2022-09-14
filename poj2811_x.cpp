#include <iostream>
#include <string>


char lamp[5],lamp_t[5],ans[5];

// void flip(char line,int i){
//     if(i == 0){

//     }
// }

void flip(char line[],char pressing){
}


int main(){
    char line[10];
    for(int i = 0;i < 6;++i){
        for(int j = 0;j < 6;++j){
            std::cin>>line[j];
        } 
        line[6] = '\0';
        lamp[i] = std::stoi(line,nullptr,2);
    }

    for(int i = 0;i < 1 << 6;++i){
        lamp_t[0] = lamp[0];
    }


    return 0;
}