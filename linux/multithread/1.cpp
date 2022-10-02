#include <iostream>
#include <thread>

void hello(){
    std::cout<<"this is thread"<<std::endl;
}

int main(){
    std::thread t(hello);
    t.join();
    std::cout<<"this is main"<<std::endl;
    return 0;
}