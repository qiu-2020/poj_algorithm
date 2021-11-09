#include <iostream>
#include <cstring>
#include <cstdlib>

int factor_Value(); // 因子
int term_Value();   // 项
int expression_value(); //表达式

int expression_value(){
    int result = term_Value();
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '+' || op == '-'){
            std::cin.get();
            int value = term_Value();
            if(op == '+') result += value;
            else result -= value;
        }
        else more = false;
    }
    return result;
}

int factor_Value(){
    if(std::cin.peek() == '('){
        std::cin.get();
        int result = expression_value();
        std::cin.get(); //接受')'
        return result;
    }
    else{
        std::string num; 
        while(std::cin.peek() >= '0' && std::cin.peek() <= '9'){
            num.append(1,std::cin.get());
        }
        if(std::cin.peek() == ')') std::cin.get();
        return atoi(num.c_str());
    }     
}

int term_Value(){
    int result = factor_Value();
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '*' || op == '/'){
            std::cin.get();
            int value = factor_Value();
            if(op == '*') result *= value;
            else result /= value;
        }
        else more = false;    
    }
    return result;
}


// int term_Value(){
//     int result = factor_Value();
//     while(true){
//         char op = std::cin.peek();
//         if(op == '*' || op == '/'){
//             int value = factor_Value();
//             if(op == '*') result *= value;
//             else result /= value;
//         }
//         else more = false;    
//     }
//     return result;
// }



int main(){
    std::cout<<expression_value()<<std::endl;



    return 0;
}