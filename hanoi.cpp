#include <iostream>
#include <stack>


class Problem{
public:
    char src,mid,des;
    int n;
    Problem(char s,char m,char d,int n):src(s),mid(m),des(d),n(n){};
};
std::stack<Problem> s;
int total;


void solve_problem(std::stack<Problem>& p){
    while(!p.empty()){
        Problem cur = p.top(); p.pop();
        if(cur.n == 1){
            // Problem tmp = p.top(); p.pop();
            std::cout<<cur.src<<"->"<<cur.des<<std::endl;
        }
        else{
            Problem tmp3('B','A','C',cur.n - 1); p.push(tmp3);
            Problem tmp2('A','B','C',1); p.push(tmp2);
            Problem tmp1('A','C','B',cur.n - 1); p.push(tmp1);
        }
    }
}

int main(){
    std::cin>>total;
    Problem p('A','B','C',total);
    s.push(p);
    solve_problem(s);

    return 0;
}