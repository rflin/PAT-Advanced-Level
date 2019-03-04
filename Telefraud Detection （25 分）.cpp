#include <bits/stdc++.h>

using namespace std;

int cnt[1024][1024];
vector<int> vs;
int parents[1024];
int finds(int x){
    return x == parents[x] ? x: parents[x] = finds(parents[x]);
}
int main()
{
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    for(int i = 0; i < m; ++i){
        int c, r, d;
        scanf("%d %d %d", &c, &r,&d);
        cnt[c][r] += d;
    }
    for(int i = 1; i <= n; ++i){
        int sum = 0, rsum = 0;
        for(int j = 1; j <= n; ++j){
            if(cnt[i][j] > 0 && cnt[i][j] <= 5) {
                ++sum;
                if(cnt[j][i] > 0) ++rsum;//统计回电话人数
            }
        }
        if(sum > k ){
            vs.push_back(i);
            if(sum > 0 && 1.0 * rsum / sum > 0.2) vs.pop_back();//去除回电话数大于20%的嫌疑人
        }

    }
    for(int i = 1; i <= n; ++i){
        parents[i] = i;
    }
    int sz = vs.size();
    for(int i = 0; i < sz; ++i){
        for(int j = i + 1; j < sz; ++j){
            if(cnt[vs[i]][vs[j]] > 0 && cnt[vs[j]][vs[i]] > 0){//嫌疑人之间有相互联系
                int L1 = finds(vs[i]), L2 = finds(vs[j]);
                if(L1 != L2){
                    if(L1 < L2) swap(L1, L2);
                    parents[L1] = L2;//小的编号作为leader
                }
            }
        }
    }
    map<int, vector<int>> mp;
    for(int i = 0; i < sz; ++i){
        int L = finds(vs[i]);
        mp[L].push_back(vs[i]);
    }
    if(mp.size() == 0){
        printf("None\n");
        return 0;
    }
    for(auto x: mp){
        sort(x.second.begin(), x.second.end());//gang内排序
        int kk = x.second.size();
        for(int i = 0; i < kk; ++i){
            printf("%d%c", x.second[i], i == kk - 1? '\n': ' ');
        }
    }
    return 0;
}
