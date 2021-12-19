#include <iostream>
#include <cstdio>
#include <cmath>

double poland(void){
    char str_tmp[10];
    char next = std::cin.peek();
    if(next == ' ') getchar();
    std::cin>>str_tmp;
    switch (str_tmp[0])
    {
    case '+': /* constant-expression */
        /* code */
        return poland() + poland();
        break;
    case '-':
        return poland() - poland();
        break;
    case '*':
        return poland() * poland();
        break;  
    case '/':
        return poland() / poland();
        break;
    default:
        return atof(str_tmp);
        break;
    }
}

int main(){
    // std::cout<<poland()<<std::endl;
    printf("%f\n",poland());
    return 0;
}