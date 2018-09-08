#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int line, s, e;
    node(){}
    node(int l, int x, int y):line(l), s(x), e(y){}
};
int visit[10000];
int minstation = 0x7fffffff;
vector<int> v[10000];
vector<node> ans(102);
map<int, int> mp;
int searchLine(int x, int y){
    if(x > y) swap(x, y);
    return mp[x * 10000 + y];
}
void setLine(int x, int y, int i){
    if(x > y) swap(x, y);
    mp[x * 10000 + y] = i;
}
void subwayMap(int lhd, int pre, int u, int e, vector<node> &rp, int station){
    if(u == e){
        rp.push_back(node(searchLine(pre, u), lhd, u));
        if(station < minstation || (station == minstation && rp.size() < ans.size())){
            minstation = station;
            ans = rp;
        }
        rp.pop_back();
        return ;
    }
    visit[u] = 1;
    for(size_t i = 0; i < v[u].size(); ++i){
        int w = v[u][i];
        if(visit[w]) continue;
        if(pre != u && searchLine(pre, u) != searchLine(u, w)){
            rp.push_back(node(searchLine(pre, u), lhd, u));
            subwayMap(u, u, w, e, rp, station + 1);
            rp.pop_back();
        }
        else subwayMap(lhd, u, w, e, rp, station + 1);
    }
    visit[u] = 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int m, x, y;
        scanf("%d %d", &m, &x);
        for(int j = 1; j < m; ++j){
            scanf("%d", &y);
            setLine(x, y, i);
            v[x].push_back(y);
            v[y].push_back(x);
            x = y;
        }
    }
    int k;
    scanf("%d", &k);
    while(k--){
        int s, e, num;
        scanf("%d %d", &s, &e);
        minstation = 0x7fffffff;
        ans.resize(102);
        vector<node> rp;
        subwayMap(s, s, s, e, rp, 0);
        num = ans.size();
        printf("%d\n", minstation);
        for(int i = 0; i < num; ++i){
            printf("Take Line#%d from %04d to %04d.\n", ans[i].line, ans[i].s, ans[i].e);
        }
    }
    return 0;
}
