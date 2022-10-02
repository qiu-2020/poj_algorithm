#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* pthread1_func(void* arg){
    while(1){
        printf("子线程1%d正在运行\n",*(int*)(arg));
        sleep(1);
        printf("**************\n");
    }
}

void* pthread2_func(void* arg){
    while(1){
        printf("子线程2%d正在运行\n",*(int*)(arg));
        sleep(1);
        printf("----------------\n");
    }
}


int main(){
    pthread_t thread1,thread2;
    int tid1 = 1,tid2 = 2;
    if(pthread_create(&thread1,NULL,&pthread1_func,&tid1) != 0)
        perror("failed to create new thread!\n");
    if(pthread_create(&thread2,NULL,&pthread2_func,&tid2) != 0)
        perror("failed to create new thread!\n");    
    while(1);

    return 0;
}