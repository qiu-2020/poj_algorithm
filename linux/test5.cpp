#include <iostream>
#include <signal.h>
#include <unistd.h>


int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        // std::cout<<"failed to fork"<<std::endl;
        perror("failed to fork");
        exit(1);
    }
    else if(pid > 0){
        while(1){
            std::cout<<"this is parent process"<<std::endl;
            std::cout<<"pid : "<<getpid()<<std::endl;
            sleep(10);
            exit(1);
        }
    }
    else{
        std::cout<<"this is child process"<<std::endl;
        sleep(3);
        kill(getppid(),SIGINT);
        while(1){

        }
    }

    

    return 0;
}