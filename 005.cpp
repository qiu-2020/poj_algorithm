#include <iostream>
const bool V = true;
const bool F = false;

bool expression();   // 由项组成，项通过|连接
bool term_value();   // 由因子组成,因子通过&连接,或者！
bool factor_value(); // 要么是单个F、V，要么是括号扩表达式 
void delete_blank(){
    while(std::cin.peek() == ' ')
        std::cin.get();
}


bool expression(){
    // bool flag;
    // if(std::cin.peek() == '!'){
    //     flag = true;
    //     std::cin.get();
    // }    
    // else flag = false;
    bool result = term_value();
    // if (flag == true) result = !result;
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '|'){
            std::cin.get();
//            delete_blank();
            bool value = term_value();
            if(value == F) result |= F;
            else result |= V;
//            delete_blank();
        }
        if(std::cin.peek() != '|') more = false;
    }
    // if(flag) return !result;
    // else    return result; 
    return result;
}

bool term_value(){
    // bool flag;
    // if(std::cin.peek() == '!'){
    //     flag = true;
    //     std::cin.get();
    // }    
    // else flag = false;
    
    bool result = factor_value();
    // if(flag) result = !result;
    bool more = true;
    while(more){
        char op = std::cin.peek();
        if(op == '&'){
            std::cin.get();
//            delete_blank();
            bool value = factor_value();
            if(value == F) result &= F;
            else result &= V;
//            delete_blank();
        }
        if(std::cin.peek() != '&') more = false;
    }
    // if(flag) return !result;
    // else return result;
    return result;
}

bool factor_value(){
    bool flag;
    delete_blank();
    if(std::cin.peek() == '!'){
        flag = true;
        std::cin.get();
        while(std::cin.peek() == '!'){
            flag = !flag;
            std::cin.get();
        }
    }    
    else flag = false;
    delete_blank();
    bool result;
    if(std::cin.peek() == '('){
        std::cin.get();
        result = expression();
        std::cin.get();
        delete_blank();
    }
    else{
        delete_blank();
        if(std::cin.peek() == 'V'){
            result = true;
            std::cin.get();
            delete_blank();
        }
        else if(std::cin.peek() == 'F'){
            result = false;
            std::cin.get();
            delete_blank();
        }      
    }
    if(flag) result = !result;
    return result;
}

int main(){
    int i = 1;
    bool more = true;
    while(std::cin.peek() != EOF){
        if(expression())
            std::cout<<"Expression "<<i<<": "<<'V'<<std::endl;
        else
            std::cout<<"Expression "<<i<<": "<<'F'<<std::endl;
        ++i;
        std::cin.clear();     
        std::cin.ignore();   
    }
    return 0;
}