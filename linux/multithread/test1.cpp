#include <iostream>
#include <thread>
#include <vector>

class TA{
public:
    // int i = 999;
    int& i;
    TA(int& m_i):i(m_i){}
    void operator()(){
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        std::cout<<"hello : "<<i<<std::endl;
        
    }
};
void hello(){
    std::cout<<"hello"<<std::endl;
    std::cout<<"hello"<<std::endl;
    std::cout<<"hello"<<std::endl;
}

int main(){
    // std::thread t1(hello);
    // std::cout<<"hello1"<<std::endl;
    // std::cout<<"hello1"<<std::endl;
    // t1.detach();
    int main_i = 999;
    TA a{main_i};
    std::thread t1(a);
    t1.join();
    return 0;
} 