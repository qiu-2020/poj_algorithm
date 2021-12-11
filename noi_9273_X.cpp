#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> ans;

// class BigInteger{
// public:
//     static const int base = 10000000;
// };

std::vector<int> add(std::vector<int>& a,std::vector<int>& b){
    std::vector<int> c; bool flag_last = false;
    for(int i = 0;i < a.size() || i < b.size();++i){
        int tmp = 0;
        c.push_back(0);
        if(flag_last) c.back() += 1;
        if(i < a.size()) tmp += a[i];
        if(i < b.size()) tmp += b[i];
        c.back() += tmp % 10;
        if(tmp >= 10) flag_last = true;
        else flag_last = false;
    }
    if(flag_last) c.push_back(1);
    return c;
}

void print_bignum(std::vector<int>& n){
    for(std::vector<int>::reverse_iterator i = n.rbegin();i != n.rend();++i){
        std::cout<<*i;
    }
    std::cout<<std::endl;
}

int count(int n){
    if(n == 1) return 1;
    else if(n == 2) return 3;
    else return count(n - 1) + 2 * count(n - 2);
}

void count_dp(void){
    for(int i = 1;i <= 250;++i){
        if(i == 1){
            std::vector<int> tmp; tmp.push_back(1); 
            ans.push_back(tmp);
        }
        else if(i == 2){
            std::vector<int> tmp; tmp.push_back(3);
            ans.push_back(tmp);
        }
        else{
            std::vector<int> t_c = add(ans[ans.size() - 2],ans[ans.size() - 2]);
            ans.push_back(add(ans[ans.size() - 1],t_c));
        }
    }
}

int main(){
    std::vector<int> t; t.push_back(1);
    ans.push_back(t);
    count_dp();
    while(std::cin>>n){
        // std::cout<<count(n)<<std::endl;
        print_bignum(ans[n]);
    }
    // std::vector<int> a; std::vector<int> b;
    // a.push_back(9);// a.push_back(9); a.push_back(1);
    // b.push_back(9);// b.push_back(9); b.push_back(9);
    // std::vector<int> c = add(a,b);
    // print_bignum(c);
    
    return 0;
}