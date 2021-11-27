#include <iostream>
#include <vector>
#include <cmath>

class block{
public:
    int k = 0;int c; 
};

std::vector<block> v;

// int max_score(){
//     while(v.size() != 0){
//         max_score_from_i(0);
//     }
// }

// void combine_erase_blocks(int);

// int max_score_from_i(int i){//从第i块考察
//     if(i == v.size() - 1){
//         int tmp = std::pow(v[i].k,2);
//         combine_erase_blocks(i);
//         return tmp;
//     }
//     else{
//         int tmp_not_add = max_score_from_i(i + 1);
//         int tmp_i = std::pow(v[i].k,2);
//         combine_erase_blocks(i);
//         int tmp_add_i = tmp_i + max_score_from_i(i);
//         return std::max(tmp_add_i,tmp_not_add);
//     }
// }
void combine_erase_blocks(int i,std::vector<block>& v){//删除并合并第i块前后
    if(i > 0 && i < v.size() - 1){
        if(v[i - 1].c == v[i + 1].c){
            v[i - 1].k += v[i + 1].k;
            v.erase(v.begin() + i + 1);
            v.erase(v.begin() + i);
        }    
        else
            v.erase(v.begin() + i);
    }
    else v.erase(v.begin() + i);
}    

// int maxscore(std::vector<block> para_v,int start){
//     if(para_v.size() == 0) return std::pow(para_v[0].k,2);
//     else{
//         std::vector<block> t_v = para_v;
//         int max_score = 0;
//         while(v.size() != 0){
//             for(int i = start;i < t_v.size();++i){ 
//                 int tmp = std::pow(t_v[i].k,2);
//                 combine_erase_blocks(i,t_v);
//                 if(tmp + maxscore(t_v,i) >= max_score) max_score = tmp + maxscore(t_v,i);
//                 t_v = para_v;  
//             } 
//         }
//         return max_score;
//     }
// }

int maxscore(std::vector<block> v){
    if(v.size() == 1){
        return std::pow(v[0].k,2);
    }
    else{
        std::vector<block> v_t = v;
        int max = 0;
        for(int i = 0;i < v_t.size();++i){
            int tmp_i = std::pow(v_t[i].k,2);
            combine_erase_blocks(i,v_t);
            int tmp = maxscore(v_t);
            if(tmp_i + tmp > max) max = tmp + tmp_i;
            v_t = v;
        }
        return max;
    }
}

int main(){
    int g;
    std::cin>>g;
    for(int i = 0;i < g;i++){
        int n,tmp_box;
        std::cin>>n;
        for(int j = 0;j < n;j++){
            block tmp;
            std::cin>>tmp_box;
            if(v.size() == 0){
                tmp.c = tmp_box;
                tmp.k++;
                v.push_back(tmp);
            } 
            else{ // size == 0
                if(v.back().c == tmp_box)
                    v.back().k++;
                else{
                    block tmp;
                    tmp.k++; tmp.c = tmp_box;
                    v.push_back(tmp);
                }    
            }
        }
        std::cout<<"Case"<<' '<<i + 1<<':'<<maxscore(v)<<std::endl;
        v.clear();
    }



    return 0;
}