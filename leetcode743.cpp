#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n + 1];bool visited[n + 1];
        for(int i = 1;i <= n;++i){
            dis[i] = 1 << 30;
            visited[i] = false;
        }    
        dis[k] = 0;

        for(int i = 0;i < n;++i){
            int min_dis = 0x3f3f3f3f,index = -1;
            for(int j = 1;j <= n;++j){
                if(!visited[j] && dis[j] < min_dis){
                    index = j;
                    min_dis = dis[j];
                }
            }
            if(index == -1) return -1;
            visited[index] = true;
            for(int j = 0;j < times.size();++j){
                if(times[j][0] == index)
                    if(dis[index] + times[j][2] < dis[times[j][1]])
                        dis[times[j][1]] = dis[index] + times[j][2];
            }
        }
        int ans = dis[1];
        for(int i = 2;i <= n;++i)
            if(ans < dis[i])
                ans = dis[i];
        return ans;        
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