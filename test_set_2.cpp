#include <iostream>
#include <set>
#include <string>

template <typename T>
class counter{
    std::string type_data;
    set<T> s;
public:
    counter(std::string str):type_data(str){}
    void Push(void* ptr){
        if(type_data == "int"){
            s.emplace(*((int*)ptr));
        }
        else if(type_data == "string")
            s.emplace(*((std::string*)ptr));
    }    

};

int main(){
    counter<int> s("int");
    int i = 1;
    int* ptr = &i;
    s.Push(ptr);


    return 0;
}