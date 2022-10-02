#include <iostream>
#include <unistd.h>
#include <cstring>

int main(int argc,char** argv){
    int fd_pipe[2];
    if(pipe(fd_pipe) == -1)
    {
        perror("failed to pipe");
    }
    pid_t pid;
    if(write(fd_pipe[1],"hello world!",sizeof("hello world!")) == -1){
        perror("failed to pipe\n");
        exit(1);
    }
    ssize_t bytes;
    char buf[100]; 
    if((read(fd_pipe[0],buf,sizeof("hello world!")) == -1))
    {
        perror("fail to read!");
        exit(1);
    }
    printf("%s",buf);



    // if((pid = fork()) < 0){
    //     perror("failed to fork");
    //     exit(1);
    // }
    // else if(pid > 0){

    // }

    return 0;
}