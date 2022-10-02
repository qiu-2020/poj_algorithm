#include <iostream>
#include <thread>

void myprint(const int & i,char* buf){
    std::cout<<i<<std::endl;
    std::cout<<buf<<std::endl;
    return;
}

int main(){
    int tmp_i = 999;
    int& ref_i = tmp_i;
    char tmp_buf[110] = "this is a test";
    std::thread t1(myprint,ref_i,tmp_buf);
    t1.join();
    return 0;
}