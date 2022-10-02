#include <iostream>
#include <unistd.h>

int main(){
    int fd_pipe[2];
    if(pipe(fd_pipe) == -1){
        perror("failed to pipe\n");
        exit(1);
    }

    write(fd_pipe[1],"hello world!",sizeof("hello world!"));
    char buf[128]{};
    if(read(fd_pipe[0],buf,sizeof(buf)) == -1){
        perror("failed to read!\n");
        exit(1);
    }
    printf("%s\n",buf);
    while(1){
        scanf("%s",buf);
        if(read(fd_pipe[0],buf,sizeof(buf)) == -1){
            perror("failed to read!\n");
            exit(1);
        } 
        std::cout<<buf<<std::endl;
    }


    return 0;
}