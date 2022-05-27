#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Diagram{
private:
    std::vector<T>  _v;  
public:
    void Push(void* ptr){
        _v.push_back(*((T*)(ptr)));
    }    
};

int main(){
    Diagram<int> v1;
    Diagram<std::string> v2;
    int *p_i = new int(99);
    std::string* p_s = new std::string("hello");
    v1.Push(p_i);
    v2.Push(p_s);

    return 0;
}