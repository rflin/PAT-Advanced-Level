#include <bits/stdc++.h>
using namespace std;
vector<int> v[10000 + 10];
vector<int> color;
map<int, int> mp;
int n, m;
bool bfs(int i, vector<int> &visit){
    queue<int> q;
    q.push(i);
    visit[i] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int x : v[s]){
            if(color[x] == color[s]) return false;
            if(!visit[x]){
                visit[x] = 1;
                q.push(x);
            }
        }
    }
    return true;
}
bool isvc(){
    vector<int> visit(n, 0);
    for(int i = 0; i < n; ++i){
        if(!visit[i]){
            if(!bfs(i, visit)) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int k;
    scanf("%d", &k);
    while(k--){
        color.clear();
        color.resize(n);
        mp.clear();
        for(int i = 0; i < n; ++i){
            scanf("%d", &color[i]);
            mp[color[i]] = 1;
        }
        if(isvc()) printf("%lld-coloring\n", mp.size());
        else printf("No\n");
    }
    return 0;
}
