#include <iostream>
#include <unistd.h>

char my_getchar(){
    char c;
    return (read(0,&c,1) == 1) ? (unsigned char) c : EOF;
}

int main(){
    char buf[BUFSIZ];
    int n;
    while((n = read(2,buf,BUFSIZ)) > 0)
        read(1,buf,n);
    return 0;    

    // std::cout<<my_getchar()<<std::endl;
}