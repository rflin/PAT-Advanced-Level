#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;
vector<vector<int>> A(1024, vector<int>(1024, inf));
vector<int> vx[1024], vy[1024], path[1024];
int indegree[1024], ind[1024];
int n, m;
stack<int> stk;
int ve[1024], vl[1024];
vector<vector<int>> vres;
vector<vector<pair<int, int>>> vel(1024, vector<pair<int, int>>(1024));
bool toplogical(){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        stk.push(x);
        for(int y: vx[x]){
            ind[y]--;
            if(ind[y] == 0) q.push(y);
            ve[y] = max(ve[y], ve[x] + A[x][y]);
        }
    }
    return (int)stk.size() == n;
}
int criticalpath(){
    if(toplogical() == 0) return -1;
    int maxval = *max_element(ve + 1, ve + 1 + n);
    fill(vl + 1, vl + 1 + n, maxval);
    while(!stk.empty()){
        int y = stk.top();
        stk.pop();
        for(int x: vy[y]){
            vl[x] = min(vl[x], vl[y] - A[x][y]);
        }
    }
    for(int x = 1; x <= n; ++x){
        for(int y: vx[x]){
            int e = ve[x], l = vl[y] - A[x][y];
            if(e == l) path[x].push_back(y);
            vel[x][y] = make_pair(e, l);
        }
    }
    return maxval;
}
void dfs(int x, vector<int> &rp){
    if(path[x].size() == 0){
        vres.push_back(rp);
        return;
    }
    for(int y: path[x]){
        rp.push_back(y);
        dfs(y, rp);
        rp.pop_back();
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        A[a][b] = A[b][a] = c;
        vx[a].push_back(b);
        vy[b].push_back(a);
        ind[b]++;
        indegree[b]++;
    }
    int res = criticalpath();
    if(res == -1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int k;
    scanf("%d", &k);
    while(k--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d %d\n", vel[x][y].first, vel[x][y].second);
    }
    printf("%d\n", res);
    for(int i = 1; i <= n; ++i){
        if(indegree[i] == 0 && path[i].size()){
            vector<int> rp(1, i);
            dfs(i, rp);
        }
    }
    sort(vres.begin(), vres.end());
    for(auto &vs: vres){
        int sz = vs.size();
        for(int i = 0; i < sz; ++i){
            printf("%d%s", vs[i], i == sz - 1 ? "\n" : "->");
        }
    }
    return 0;
}
