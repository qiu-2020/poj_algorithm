#include <iostream>
#include <cstring>

const int MAX = 1010;
int father[MAX];

int findFather(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}

int find_union_recursion(int x){
    if(x != father[x])
        father[x] = find_union_recursion(father[x]);
    return father[x];    
}
int find_union(int x){
    while(x != father[x]){
        father[x] = father[father[x]];
    }
}


void union_two_set(int a,int b){
    int fa = findFather(a),fb = findFather(b);
    if(fa != fb)
        father[fa] = fb;
}



int main(){



    return 0;
}