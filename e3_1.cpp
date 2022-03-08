#include <iostream>

// 表达式 = 项 +、- 项
// 项 = 因子 *、/ 因子
// 因子 = （表达式）、整数
// (2 + 3) * (5 + 7) + 9 / 3
int poly_value(void);
int factor_value(void);

int exp_value(){
    int result = poly_value();
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '+'){
            std::cin.get();
            result += poly_value();
        }
        else if(op == '-'){
            std::cin.get();
            result -= poly_value();
        }
        else more = false;     
    }
    return result;
}
int poly_value(){
    int result = factor_value();
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '*'){
            std::cin.get();
            result *= factor_value();
        }
        else if(op == '/'){
            std::cin.get();
            result /= factor_value();
        }
        else more = false;
    }
    return result;
}
// 表达式 = 项 +、- 项
// 项 = 因子 *、/ 因子
// 因子 = （表达式）、整数
// (2 + 3) * (5 + 7) + 9 / 3

int factor_value(){
    char s = std::cin.peek();
    int result;
    if(s == '('){
        std::cin.get();
        result = exp_value();
        std::cin.get();
    }
    else if(s >= '0' && s <= '9'){
        result = std::cin.get() - '0';
    }
    return result;
}

int main(){
    std::cout<<exp_value()<<std::endl;
    return 0;
}