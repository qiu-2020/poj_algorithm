#include <iostream>
#include <string>
#include <cmath>

double exp(void){
    std::string str;
    std::cin>>str;
    switch (str[0])
    {
        case '+':
            return exp() + exp();
        case '-':
            return exp() - exp();
        case '*':
            return exp() * exp();
        case '/':
            return exp() / exp();    
        default:
            return atof(str.c_str());
    }
}

int main(){
    // std::cout<<exp()<<std::endl;
    printf("%f\n",exp());
    return 0;
}