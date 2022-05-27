#include <iostream>
#include <cmath>


int total_deep;

void print_triangle(int level){
    if(level == 1){
        print_up();
    }
}
void print_up(){
    std::cout<<" /\\";
}
void print_down(){
    std::cout<<"/__\\";
}

int main(){
    for(int i = 0;i < 3;++i)
        print_triangle();
    return 0;
}