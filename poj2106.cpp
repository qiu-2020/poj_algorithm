#include <iostream>

// 表达式 = 表达式 | 表达式
// 项 = 项 & 项
// 因子 = 常量 、！常量 、（表达式）
char exp_value(void);
char term_value(void);
char factor_value(void);

void delete_blank(){
    while(std::cin.peek() == ' ')
        std::cin.get();
}

char exp_value(void){
    delete_blank();
    char result = term_value();
    bool more = true;
    while(more){
        delete_blank();
        if(std::cin.peek() == '|'){
            std::cin.get();
            delete_blank();
            char tmp_result = term_value();
            if(tmp_result == 'V' || result == 'V')
                result = 'V';
            else result = 'F';    
        }
        else more = false;
    }
    return result;
}

// 表达式 = 表达式 | 表达式
// 项 = 项 & 项
// 因子 = 常量 、！常量 、（表达式）

char term_value(void){
    delete_blank();
    char result = factor_value();
    bool more = true;
    while(more){
        delete_blank();
        if(std::cin.peek() == '&'){
            std::cin.get();
            delete_blank();
            char tmp_result = factor_value();
            if(result == 'F' || tmp_result == 'F')
                result = 'F';
            else result = 'V';    
        }
        else more = false;
    }
    return result;
}
// 因子 = !因子、！(表达式) 、（表达式）
char factor_value(void){
    delete_blank();
    char result;
    if(std::cin.peek() == '!'){
        // std::cin.get();
        // delete_blank();
        // result = exp_value();
        // if(result == 'V') result = 'F';
        // else if(result == 'F') result = 'V';
        std::cin.get();
        delete_blank();
        result = factor_value();
        if(result == 'V') result = 'F';
        else result = 'V';

    }
    else if(std::cin.peek() == '('){
        std::cin.get();
        delete_blank();
        result = exp_value();
        delete_blank();
        std::cin.get();
    }
    else result = std::cin.get();
        // (std::cin.peek() == 'V' || std::cin.peek() == 'F'
    return result;    
}
// !  V | V


int main(){
    int i = 1;
    while(std::cin.peek() != EOF){
        std::cout<<"Expression "<<i<<": "<<exp_value()<<std::endl;
        ++i;
        std::cin.clear();
        std::cin.ignore();
    }

    return 0;
}