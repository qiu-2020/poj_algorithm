#include <iostream>
#include <cstring>
using namespace std;
//int N,M;
// char charm[3500][2]; 
// int N,M;
// int ans[12880];//i ~ N - 1放入room个空间

// int bracelet(int i,int room){ // 从第i(0 ~ N - 1)个到最后的放法
//     if(i == N - 1){
//         if(room >= charm[i][0]) return charm[i][1];
//         else return 0;
//     }
//     else{
//         if(room >= charm[i][0]){
//             return std::max(bracelet(i + 1,room - charm[i][0]) + charm[i][1],bracelet(i + 1, room));
//         }
//         else return bracelet(i + 1,room);
//     }
// }

// int bracelet_2(int i,int room){
//     int tmp;
//     if(ans[i][room] >= 0) return ans[i][room];
//     if(i == N ) tmp = 0;
//     else if(room < charm[i][0]) return tmp = bracelet_2(i + 1,room);
//     else tmp = std::max(bracelet_2(i + 1,room - charm[i][0]) + charm[i][1],bracelet_2(i + 1,room));
//     ans[i][room] = tmp;
//     return tmp;
// }

// int bracelet(int i,int room){ //计算前i个物品，在容量为room的前提下的最大价值
//     if(i == 0){
//         int max = 0;
//         for(int j = 0;j < N;j++){
//             if(charm[j][0] <= room && charm[j][0] > max){
//                 ans[room] = charm[j][0];
//             }
//         }
//         return ans[room];
//     }
//     else{
//         int tmp = 0;
//         if()
//     }
// }

// C++ Version
int n, t;
int tcost[3402], mget[3402];
int mem[3402][12881];
int dfs(int pos, int tleft) {
  if (mem[pos][tleft] != -1) return mem[pos][tleft];
  if (pos == n + 1) return mem[pos][tleft] = 0;
  int dfs1, dfs2 = -1;
  dfs1 = dfs(pos + 1, tleft);
  if (tleft >= tcost[pos]) dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];
  return mem[pos][tleft] = max(dfs1, dfs2);
}
int main() {
  memset(mem, -1, sizeof(mem));
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
  cout << dfs(1, t) << endl;
  return 0;
}

// int main(){
//     std::cin>>N>>M;
//     memset(ans,-1,sizeof(ans)); //-1机器码全为1，高字节与低字节完全一致！
//     for(int i = 0;i < N;i++)
//         std::cin>>charm[i][0]>>charm[i][1];
//     std::cout<<bracelet(N - 1,M)<<std::endl;
//     return 0;
// }