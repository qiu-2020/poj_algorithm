#include <iostream>
#include <syscall.h>
#include <unistd.h>

int main(int argc,char** argv){
    std::cout<<"pid = "<<getpid()<<std::endl;
    while(1){

    }


    return 0;
}