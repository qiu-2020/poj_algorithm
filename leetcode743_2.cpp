#include <iostream>
#include <vector>
#include <cstring>

using std::vector;

class Solution {
public:
    //bellman ford
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n + 1];
        bool vis[n + 1];
        bool relaxed = false;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[k] = 0;vis[k] = true;
        for(int i = 0;i < n - 1;++i){
            relaxed = false;
            for(int j = 0;j < times.size();++j){
                if(vis[times[j][0]] && dis[times[j][1]] > dis[times[j][0]] + times[j][2]){
                    dis[times[j][1]] = dis[times[j][0]] + times[j][2];
                    relaxed = true;
                    vis[times[j][1]] = true;
                }
            }
            if(!relaxed) break;
        }
        for(int i = 0;i < times.size();++i){
            if(vis[times[i][0]] && dis[times[i][1]] > dis[times[i][0]] + times[i][2])
            return -1;
        }
        int min_ans = 0;
        for(int i = 1;i <= n;++i)
            if(min_ans < dis[i])
                min_ans = dis[i];
        if(min_ans == 0x3f3f3f3f)
            return -1;        
        else return min_ans;        

    }
};


int main(){
    vector<vector<int>> t1({{2,1,1},{2,3,1},{3,4,1}}),t2({{1,2,1}}),t3({{1,2,1}});
    int n1(4),n2(2),n3(2),k1(2),k2(1),k3(2);
    Solution s;
    std::cout<<s.networkDelayTime(t1,n1,k1)<<std::endl;
    std::cout<<s.networkDelayTime(t2,n2,k2)<<std::endl;
    std::cout<<s.networkDelayTime(t3,n3,k3)<<std::endl;

    return 0;
}