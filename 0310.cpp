#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

multiset<int> s;
int a[5000 + 5];

int main() {
	int n, T, k;
	scanf("%d", &T);
	while (T--) {
		s.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d", a + i);
			s.insert(a[i]);
		}
		bool flag = false;
		scanf("%d", &k);
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				int target = k - a[i] - a[j], min_count = 1;
// 在此处补充你的代码
                // for(int l = 0;l < n;++l)
                //     if(target == a[l] && a[l] != a[i] && a[l] != a[j]) flag = true;
                auto i1 = s.find(a[i]);
                s.erase(i1);
                auto i2 = s.find(a[j]);
                s.erase(i2);
                int x1 = *i1,x2 = *i2;
                
                if(s.find(target) != s.end()){
                    flag = true;
                    break;
                }    
                else{
                    s.emplace(x1);s.emplace(x2);
                }        

            }
			if (flag) break;
		}
		puts(flag? "Yes": "No");
	}
}