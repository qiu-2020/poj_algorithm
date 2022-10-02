#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void* arg){
    static int num = 666;
    printf("子线程%d正在运行\n",*(int*)arg);
    sleep(10);
    printf("子线程要退出了\n");
    // return (void*)&num;
    // pthread_exit((num));
}


int main(int argc,char** argv){
    printf("主控线程正在执行\n");
    pthread_t thread;
    int i = 1;
    if(pthread_create(&thread,NULL,thread_fun,(void*)(&i)) != 0){
        perror("fail to phread_create\n");
        exit(1);
    }
    int* ret_num = new int(1);
    if(pthread_join(thread,(void**)(&ret_num)) != 0){
        perror("fail to pthread_join\n");
        exit(1);
    }

    printf("进程要退出了\n");


    return 0;
}