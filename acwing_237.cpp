#include <iostream>
#include <set>

int fa[200010];

int Get_fa(int x){
    if(x == fa[x]) return x;
    fa[x] = Get_fa(fa[x]);
    return fa[x];
}

void merge(int a,int b){
    if(a != b)
        fa[a] = Get_fa(b);
}

class exp{
public:
    int a,b,equal;
    bool operator<(const exp& e)const{
        if(a == e.a && b == e.b && equal == e.equal || a == e.b && b == e.a && equal == e.equal) return false;
        else return !(equal < e.equal);
    }
};

std::set<exp> s;

int main(){
    int n,N,a,b,e;
    std::cin>>n;
    for(int i = 0;i < n;++i){
        s.clear();
        std::cin>>N;
        for(int j = 0;j < N;++j){
            std::cin>>a>>b>>e;
            exp tmp;
            tmp.a = a;tmp.b = b;tmp.equal = e;
            fa[a] = a;fa[b] = b;
            s.emplace(tmp);
        }
        bool ans = true;
        for(std::set<exp>::iterator it = s.begin();it != s.end();it++){
            int f_a = Get_fa(it->a);int f_b = Get_fa(it->b);
            if(it->equal == 1){
                merge(f_a,f_b);
            }
            else{
                if(f_a == f_b){
                    ans = false;
                    break;
                }
            }
        }
        if(ans) std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
    }

    return 0;
}