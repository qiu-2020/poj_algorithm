#include <iostream>
#include <unistd.h>


int main(){
    int fd_pipe[2];
    if(pipe(fd_pipe) == -1){
        perror("failed to pipe");
        exit(1);
    }

    pid_t pid;

    if((pid = fork()) < 0){
        perror("failed to pipe\n");
        exit(1);
    }
    else if(pid > 0){
        //父进程写入
        // char buf[128] = {};
        if(write(fd_pipe[1],"hello world!",sizeof("hello world!")) < 0){
            perror("failed to write\n");
        }
    }
    else{
        char buf[128] = {};
        if(read(fd_pipe[0],buf,sizeof(buf)) == -1){
            perror("fail to read!\n");
            exit(1);
        }
        printf("from parent: %s\n",buf);
    }



    return 0;
}