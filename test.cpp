#include <iostream>
#include <string>
void test(std::string& s){
    std::cout<<s<<std::endl;
}

int main(){

//    test(std::string("AAA"));
    std::string str("ABC");
    test(str);

    return 0;
}