#include <iostream>
#include <unistd.h>
#include <signal.h>

int main(int argc,char** argv){
    pid_t pid = fork();
    if(pid < 0) std::cout<<"fork failed"<<std::endl;
    else if(pid > 0){
        std::cout<<"this is parent process"<<std::endl;
        pause();
        std::cout<<"signal is paused!"<<std::endl;
        while(1){}
        std::cout<<"signal is paused twice!"<<std::endl;
    }
    else{
        std::cout<<"this is son process!"<<std::endl;
        sleep(3);
        kill(getppid(),SIGINT);
        kill(getppid(),SIGINT);
        std::cout<<"2 signal sended!"<<std::endl;
    }

    return 0;
}