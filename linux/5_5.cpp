#include <iostream>
#include <pthread.h>

using namespace std;
const int NUM_THREAD = 5;

// void* say_hello(void* args){
//     std::cout<<"hello"<<std::endl;
//     return 0;
// }

void* printHello(void* threadIDs){
    int tid = *((int*)threadIDs);
    std::cout<<"hello runoob!"<<tid<<std::endl;
    pthread_exit(NULL);
}

int main(){
    // pthread_t tids[NUM_THREAD];
    // for(int i = 0;i < NUM_THREAD;++i){
    //     int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
    //     if(ret != 0){
    //         cout << "pthread_create error: error_code=" << ret << endl;
    //     }
    // }
    // pthread_exit(NULL);
    pthread_t threads[NUM_THREAD];
    int ret;
    int indexes[NUM_THREAD]{1,2,3,4,5};
    for(int i = 0;i < 5;++i){
        ret = pthread_create(&threads[i],NULL,printHello,(void*)&(indexes[i]));
        if(ret != 0){
            cout << "pthread_create error: error_code=" << ret << endl;
        }
        if(i == 2)
            exit(0);
    }
    pthread_exit(NULL);
    return 0;
}