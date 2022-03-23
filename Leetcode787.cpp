#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int dis[n];
        bool flag[n];
        for(int i = 0;i < n;++i){
            dis[i] = 1 << 30;
            flag[i] = false;
        }    
        dis[src] = 0;
        for(int i = 0;i < k;++i){
            for(int f = 0;f < n;f++)
                flag[f] = false;
            int d_pre[n];   
            for(int j = 0;j < flights.size();++j){
                if(dis[flights[j][0]] != (1 << 30) && dis[flights[j][1]] > dis[flights[j][0]] + flights[j][2]){
                    if(flag[flights[j][0]]){
                        dis[flights[j][1]] = d_pre[flights[j][0]] + flights[j][2];    
                    }
                    d_pre[flights[j][1]] = dis[flights[j][1]];
                    dis[flights[j][1]] = dis[flights[j][0]] + flights[j][2];
                    flag[flights[j][1]] = true;
                    }
            }
        }
        for(int i = 0;i < flights.size();++i){
            if(flights[i][1] == dst){
                if(dis[flights[i][0]] != (1 << 30) && dis[flights[i][1]] > dis[flights[i][0]] + flights[i][2])
                    dis[flights[i][1]] = dis[flights[i][0]] + flights[i][2];
            }
        }
        if(dis[dst] == (1 << 30)) return -1;
        else return dis[dst];
        
    }    

// 如果当前这条边的权重 + 走小于等于k-1条边到a点的距离小于源点到b的距离 则更新


};

int main(){
    vector<vector<int>> input1({{0,1,100},{1,2,100},{0,2,500}}),input2({{0,1,100},{1,2,100},{0,2,500}}),input3({{0,1,2},{1,2,1},{2,0,10}}),input4({{0,1,1},{0,2,5},{1,2,1},{2,3,1}});
    int n1 = 3,src1 = 0, dst1 = 2, k1 = 1;
    int n2 = 3, src2 = 0, dst2 = 2, k2 = 0;
    int n3 = 3,src3 = 1,dst3 = 2,k3 =1;
    int n4 = 4,src4 = 0,dst4 = 3,k4 = 1;
    Solution s;
    std::cout<<s.findCheapestPrice(n1,input1,src1,dst1,k1)<<std::endl;
    std::cout<<s.findCheapestPrice(n2,input2,src2,dst2,k2)<<std::endl;
    std::cout<<s.findCheapestPrice(n3,input3,src3,dst3,k3)<<std::endl;
    std::cout<<s.findCheapestPrice(n4,input4,src4,dst4,k4)<<std::endl;
    return 0;
}