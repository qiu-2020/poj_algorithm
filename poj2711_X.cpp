#include <iostream>
#include <cstring>
const int MAX = 110;
int T[MAX],N;
bool flag[MAX];

// T1 < T2 < T3 < ... < TK i == N
// T1 > T2 > T3 > ... > TK i == 1

int count(int i){
    int index = i,out = 0,next;
    if(i == 1){
        next = index + 1;
        while(index != N){
            if(next == N + 1) break; 
            if(T[index] > T[next]){
                index = next;
                next++;
            }
            else{
                next++;
                out++;
            }
        }
    }
    else if(i == N){
        next = N - 1;
        while(index != 0){
            if(next == 0) break;
            if(T[index] > T[next]){
                index = next;
                next--;
            }
            else{
                next--;
                out++;
            }
        }
    }
    else{
        next = index + 1;
        while(index != N){
            if(next == N + 1) break; 
            if(T[index] > T[next]){
                index = next;
                next++;
            }
            else{
                next++;
                out++;
            }
        }
        index = i,next = i - 1;
        while(index != 0){
            if(next == 0) break;
            if(T[index] > T[next]){
                index = next;
                next--;
            }
            else{
                next--;
                out++;
            }
        }
    }
    return out;
}


int main(){
    std::cin>>N;
    int tmp = 110;
    for(int i = 1;i <= N;++i) 
        std::cin>>T[i];
    for(int i = 1;i <= N;++i)
        if(count(i) < tmp)
            tmp = count(i);
    std::cout<<tmp<<std::endl;        
    return 0;
}


