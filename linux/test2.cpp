#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>


int main(){
    pid_t pid = fork();
    if(pid <  0){
        std::cout<<"fork failed!"<<std::endl;
        exit(1);
    }
    else if(pid == 0){
        std::cout<<"this is son process!"<<std::endl;
        sleep(3);
        kill(getppid(),SIGINT);
    }
    else{
        std::cout<<"this is parent process1"<<std::endl;     
        pause();
        std::cout<<"this is parent process2"<<std::endl;     
    }


    return 0;
}