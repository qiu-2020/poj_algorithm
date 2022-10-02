#include <iostream>
#include <unistd.h>
#include <wait.h>

int main(){
    // fork();
    // std::cout<<"helloworld!"<<std::endl;
    // std::cout<<getpid()<<std::endl;
    // while(1){
    //     ;
    // }
    // while(1){
    //     std::cout<<"hello world!"<<std::endl;
    //     sleep(2);
    // }

    int id = fork();
    if(id == -1){
        std::cout<<"failed!"<<std::endl;
    }
    else if(id == 0){
        for(int i = 0;i < 5;++i){
            std::cout<<"hello"<<std::endl;
            sleep(1);
        }
        exit(999);
    }
    else{
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            std::cout<<"the son exit status is "<<WEXITSTATUS(status)<<std::endl;    
        }
        std::cout<<"this is father process"<<std::endl;
    }
    return 0;
}