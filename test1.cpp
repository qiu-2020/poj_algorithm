#include <iostream>
#include <set>
#include <string>

template <typename T>
class counter{
    std::string type_data;
    std::set<T> _s;
public:
    counter(std::string str):type_data(str){
        // _size = 0;
    }
    void Push(void* ptr){
        _s.emplace(*((T*)(ptr)))

        // if(type_data == "int"){
        //     _s.emplace(*((int*)ptr));
        //     // _s[_size++] = *((int*)ptr);
        // }
        // else if(type_data == "string")
        //     _s.emplace(*((std::string*)ptr));
        //     // _s[_size++] = *((std::string*)ptr);
    }    
};

// void print(void* p){
//     std::cout<<*((int *) p);
// }

// class str{
//     std::string s;
// public:
//     str(std::string s_):s(s_){}
//     void Push(void* p){
//         s += *((std::string*)(p));
//     }
// };
int main(){
    counter<int> s1("int");
    counter<std::string> s2("string");
    int i = 1;
    int* ptr = &i;
    std::string str("hello");
    std::string* ptr2= &str;
    s2.Push(ptr2);
    // s1.Push(ptr);
    // int i = 999;
    // print(&i);

    // str sss("string");
    // std::string ss = "isgood";
    // std::string* p_s = &ss;
    // sss.Push(p_s);

    return 0;
}