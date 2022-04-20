#include <iostream>

class mychar{
public:
    char _c;
    mychar(char c):_c(c){}
};

std::ostream& operator<<(std::ostream& os,const mychar& c){
    os<<c._c;
    return os;
}

int main(){
    mychar c('?');
    std::cout<<'!'<<std::endl;
    std::cout<<'!'<<c<<'!'<<std::endl;

    return 0;
}