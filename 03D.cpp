#include <iostream>
#include <cstring>


int trees[110][2];
int p_sum[110];
int b_sum[110];
int ans_p[110][110];
int ans_b[110][110];

int main(){
    int honey,bee,peach,num;
    while(std::cin>>honey && honey != -1){
        num = 0;
        int ans = 0;
        memset(trees,0,sizeof(trees));
        memset(p_sum,0,sizeof(p_sum));
        memset(b_sum,0,sizeof(b_sum));
        memset(ans_p,0,sizeof(ans_p));
        memset(ans_b,0,sizeof(ans_b));

        while(std::cin>>peach>>bee && peach != -1 && bee != -1){
            trees[num][0] = peach;
            trees[num][0] = bee;
            num++;
        }
        p_sum[0] = trees[0][0];
        b_sum[0] = trees[0][1];
        for(int i = 1;i < num;++i){
            p_sum[i] = p_sum[i - 1] + trees[i][0];
            b_sum[i] = p_sum[i - 1] + trees[i][1];
        }
        for(int i = 0;i < num;++i){
            for(int j = i;j < num;++j){
                if(i == j){
                    ans_p[i][j] = p_sum[i];
                    ans_b[i][j] = b_sum[i];
                }
                ans_p[i][j] = p_sum[j] - p_sum[i];
                ans_b[i][j] = b_sum[j] - b_sum[i];
                if(ans_b[i][j] <= honey){
                    if(ans < ans_p[i][j])
                        ans = ans_p[i][j];
                }
            }
        }
        std::cout<<ans<<std::endl;
    }

    return 0;
}