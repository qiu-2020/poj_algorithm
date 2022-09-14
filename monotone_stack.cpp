#include <iostream>

class num{
private:
    int _n,_c;
public:
    num():_n(0),_c(0){};
    num(int n):_n(n),_c(0){};
    void add(){
        _c++;
    }
    int get_val(){
        return _n;
    }     
};
num stack[110];

int main(){
    int x,top = 0;
    while(std::cin>>x){
        if(top == 0) stack[top++] = num(x);
        else{
            int i = top - 1;
            while(num){
                
            }
        }
    }


    return 0;
}