// #include <iostream>

// class myClass{
// public:
//     myClass* operator->(){
//         return this;
//     }
//     myClass* action(){
//         // std::cout<<"recursion!"<<std::endl;
//         return this;
//     }
// };

// int main(){
//     myClass a;
//     a->action();
//     // (a.operator->())->action()
//     // (& a )->action()
//     // a

//     // (a.operator->())->action()
//     return 0;
// }

#include <iostream>
    
class myClass {
public:
    myClass& operator->() {
        std::cout << "myClass ->() is called!" << std::endl;
        return *this;
    }
    void action() {
        std::cout << "myClass action() is called!" << std::endl;
        return;
    }
};
    
int main() {
    myClass obj;
    //obj->action();
    // (obj.operator->())->action()
    // ...
    // obj->action()
    
    return 0;
}

