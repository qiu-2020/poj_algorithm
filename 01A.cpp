#include <iostream>

int A[110],B[110];

int compare_(int a,int b){
    // 1 : A win 
    // 2 : draw 
    // 3 : B win
    if(a == b) return 2;
    else if(a == 0 && b == 2 || a == 2 && b == 5 || a == 5 && b == 0) return 1;
    else return 3;
    // A win
}

int main(){
    int N,NA,NB;
    std::cin>>N>>NA>>NB;
    for(int i = 0;i < NA;++i)
        std::cin>>A[i];
    for(int i = 0;i < NB;++i)
        std::cin>>B[i]; 
    int count_Awin = 0,count_Bwin = 0;
    for(int i = 0;i < N;++i){
        if(compare_(A[i % NA],B[i % NB]) == 1)
            count_Awin++;
        else if(compare_(A[i % NA],B[i % NB]) == 3)
            count_Bwin++;
    }    
    if(count_Awin == count_Bwin)
        std::cout<<"draw"<<std::endl;
    else if(count_Awin > count_Bwin) std::cout<<"A"<<std::endl;
    else std::cout<<"B"<<std::endl;

    return 0;
}