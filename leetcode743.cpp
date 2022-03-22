#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n];
        bool visited[n];
        for(int i = 0;i < n;++i){
            dis[i] = 1 << 30;
            visited[i] = false;
        }    
        dis[k] = 0;
        int t[n][n];
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                t[i][j] = 1 << 30;
        for(int i = 0;i < times.size();++i){
            t[times[i][0]][times[i][1]] = times[i][2];
        }
        for(int i = 0;i < n;++i){
            int min_dis = 1 << 30,min_index = -1;
            for(int j = 0;j < n;++j){
                if(dis[i] < min_dis){
                    min_dis = dis[i];
                    min_index = i;
                }
            }
            if(min_index == -1) return -1;
            visited[min_dis] = true;
            for(int j = 0;j < n;++j){
                if(!visited[j] && t[min_dis][j] + dis[min_index] < dis[j])
                    dis[j] = t[min_dis][j] + dis[min_index];
            }
        }
        int ans = dis[0];
        for(int i = 1;i < n;++i){
            if(dis[i] > ans)
                ans = dis[i];
        }
        if(ans == 0x3f3f3f3f)   return -1;
        else return ans; 
    }


};

int main(){
    // memset(dis,0x3f,sizeof(dis));
    vector<vector<int>> times1({{2,1,1},{2,3,1},{3,4,1}}),times2({{1,2,1}}),times3({{1,2,1}});
    int n1= 4,k1 = 2,n2 = 2,k2 = 1,n3 = 2,k3 = 2;
    Solution s;
    std::cout<<s.networkDelayTime(times1,n1,k1)<<std::endl;
    std::cout<<s.networkDelayTime(times2,n2,k2)<<std::endl;
    std::cout<<s.networkDelayTime(times3,n3,k3)<<std::endl;
    return 0;
}