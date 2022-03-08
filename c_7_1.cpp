#include <iostream>
#include <cstring>

int main(int argc,char* argv[]){
    for(int i = 0;i < strlen(argv[1]);++i){
        if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
            argv[1][i] -= 'a' - 'A';
        else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            argv[1][i] += 'a' - 'A';   
    }
    std::cout<<argv[1]<<std::endl;

    return 0;
}