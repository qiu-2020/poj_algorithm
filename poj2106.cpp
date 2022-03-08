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




// char exp_value(){
//     delete_blank();
//     char result,result1 = term_value();
//     bool more = true;
//     while(more){
//         delete_blank();
//         char s = std::cin.peek();
//         if(s == '|'){
//             std::cin.get();
//             delete_blank();
//             char result2 = term_value();
//             if(result1 == 'V' || result2 == 'V')
//                 result = 'V';
//             else result = 'F';    
//         }
//         else more = false;
//     }
//     return result;
// }
// char term_value(){
//     delete_blank();
//     char result,result1 = factor_value();
//     bool more = true;
//     while(more){
//         delete_blank();
//         char s = std::cin.peek();
//         if(s == '&'){
//             delete_blank();
//             char result2 = factor_value();
//             if(result1 == 'F' || result2 == 'F')
//                 result = 'F';
//             else result = 'V';    
//         }
//         else more = false;
//     }
//     return result;
// }
// char factor_value(){
//     char result;
//     delete_blank();
//     if(std::cin.peek() == '!'){
//         std::cin.get();
//         delete_blank();
//         char s = std::cin.get();
//         if(s == 'V') result = 'F';
//         else result = 'V';
//     }
//     else if(std::cin.peek() == 'V' || std::cin.peek() == 'F'){
//         delete_blank();
//         result = std::cin.get();
//     }    
//     else if(std::cin.peek() == '('){
//         std::cin.get();
//         delete_blank();
//         result = exp_value();
//         delete_blank();
//         std::cin.get();
//     }
//     return result;
// }

int main(){
    // int i = 1;
    // std::cout<<"Expression "<<i<<": "<<exp_value()<<std::endl;
    // ++i;
    // while(std::cin.peek() != EOF && std::cin.peek() != '\n'){
    //     std::cout<<"Expression "<<i<<": "<<exp_value()<<std::endl;
    //     ++i;
    // }
    // std::cout<<exp_value()<<std::endl;

    return 0;
}