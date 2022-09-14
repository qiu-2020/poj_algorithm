#include <iostream>

int trees[110][2],num,w,s,ans;
void max_income(int i,int s,int this_income){
    if(i >= num){
        if(this_income >= ans) ans = this_income;
        return;
    }
    if(s >= trees[i][1]){
        max_income(i + 1,s - trees[i][1],this_income + trees[i][0]);
        max_income(i + 1,s,this_income);
    }    
    else max_income(i + 1,s,this_income);
}


int main(){
    // int w,s;
    int peach,bee;
    while(std::cin>>s && s != -1){
        num = 0;
        w = 0;
        ans = 0;
        while(std::cin>>peach>>bee && peach != -1 && bee != -1){
            trees[num][0] = peach;
            trees[num][1] = bee;
            ++num;
        }
        max_income(0,s,0);
        std::cout<<ans<<std::endl;
    }


    return 0;
}