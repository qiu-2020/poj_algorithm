// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
// #include <map>
using namespace std;

int a[210];
// map<int,int> m;

int main() {
    int n,q;
    std::cin>>n>>q;
    for(int i = 0;i < n;++i){
        std::cin>>a[i];
        // m[a[i]]++;
    }    
    int cmd,index,x,ans = 0;
    for(int i = 0;i < q;++i){
        std::cin>>cmd>>index>>x;
        if(cmd == 1){
            // m[a[index]]--;
            a[i - 1] = x;
        }
        else if(cmd == 2){
            // std::cout<<m[index]<<std::endl;
            ans = 0;
            for(int i = 0;i < index - 1;++i){
                if(a[i] == x)
                    ans++;
            }
            std::cout<<ans<<std::endl;
        }
    }
    return 0;
}