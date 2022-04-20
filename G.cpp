#include <iostream>
#include <queue>



class compare{
public:
    bool operator()(const int& a,const int& b){

    }
};
std::vector<int,compare> pri_queue;

int main(){
    int num,x;
    std::cin>>num;
    for(int j = 0;j < num;++j){
        for(int i = 0;i < 10;++i){
            std::cin>>x;
            pri_queue.push_back(x);
        }
        std::cout<<pri_queue.front()<<' '<<pri_queue[pri_queue.size() - 1]<<std::endl;
    }

    return 0;
}

// 2 5 ; 7 ; 2 3 11; 2 2;1 5; 3  2 5; 91 ; 2 2 5 5;2 2 2;3 3 