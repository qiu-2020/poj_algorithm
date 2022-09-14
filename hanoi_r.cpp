#include <iostream>
#include <stack>

class A{
public:
    char src,via,des;
    int _n;
    A(int s,int v,int d,int n):src(s),via(v),des(d),_n(n){}
};
std::stack<A> s;

int main(){
    A a('A','B','C',3);
    s.push(a);
    while(!s.empty()){
        A t = s.top();
        s.pop();
        if(t._n == 1)
            std::cout<<t.src<<"->"<<t.des<<std::endl;
        // else if(t._n == 2){
        //     A t1('A','C','B',t._n - 1); 
        //     s.push(t1);
        //     A t2('A','B','C',1);
        //     s.push(t2);
        // }
        else{
            A t1(t.src,t.des,t.via,t._n - 1);
            A t2(t.src,t.via,t.des,1);
            A t3(t.via,t.src,t.des,t._n - 1);
            s.push(t3);
            s.push(t2);
            s.push(t1);
        }
    }



    return 0;
}