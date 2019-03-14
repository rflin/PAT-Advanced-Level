#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;
int n, m, s, e;
vector<vector<int>> vl(512, vector<int>(512, inf));
vector<vector<int>> vt(512, vector<int>(512, inf));
vector<int> spath[512], anssp, tpath[512], anstp;
int minshorttime = inf, minintsec = inf;

void shortlen(int s, int e){
    vector<int> dist = vl[s];
    vector<int> visit(n, 0);
    for(int i = 0; i < n; ++i){
        if(dist[i] < inf) spath[i].push_back(s);
    }
    visit[s] = 1;
    while(true){
        int minval = inf, u = -1;
        for(int i = 0; i < n; ++i){
            if(visit[i] == 0 && minval > dist[i]) minval = dist[u = i];
        }
        if(u == -1) break;
        visit[u] = 1;
        for(int w = 0; w < n; ++w){
            if(vl[u][w] < inf && visit[w] == 0){
                if(dist[w] > dist[u] + vl[u][w]){
                    dist[w] = dist[u] + vl[u][w];
                    spath[w].clear();
                    spath[w].push_back(u);
                }
                else if(dist[w] == dist[u] + vl[u][w]){
                    spath[w].push_back(u);
                }
            }
        }
    }
}
void spdfs(int y, int t, vector<int> &rsp){
    if(y == s){
        if(t < minshorttime){
            minshorttime = t;
            anssp = rsp;
        }
        return;
    }
    for(int x: spath[y]){
        rsp.push_back(x);
        spdfs(x, t + vt[x][y], rsp);
        rsp.pop_back();
    }
}
void shorttime(int s, int e){
    vector<int> dist = vt[s];
    vector<int> visit(n, 0);
    for(int i = 0; i < n; ++i){
        if(dist[i] < inf) tpath[i].push_back(s);
    }
    visit[s] = 1;
    while(true){
        int minval = inf, u = -1;
        for(int i = 0; i < n; ++i){
            if(visit[i] == 0 && minval > dist[i]) minval = dist[u = i];
        }
        if(u == -1) break;
        visit[u] = 1;
        for(int w = 0; w < n; ++w){
            if(vt[u][w] < inf && visit[w] == 0){
                if(dist[w] > dist[u] + vt[u][w]){
                    dist[w] = dist[u] + vt[u][w];
                    tpath[w].clear();
                    tpath[w].push_back(u);
                }
                else if(dist[w] == dist[u] + vt[u][w]){
                    tpath[w].push_back(u);
                }
            }
        }
    }
}
void tpdfs(int y, int intsec, vector<int> &rtp){
    if(y == s){
        if(intsec < minintsec){
            minintsec = intsec;
            anstp = rtp;
        }
        return;
    }
    for(int x: tpath[y]){
        rtp.push_back(x);
        tpdfs(x, intsec + 1, rtp);
        rtp.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int v1, v2, ow, l, t;
        scanf("%d %d %d %d %d", &v1, &v2, &ow, &l, &t);
        vl[v1][v2] = l;
        vt[v1][v2] = t;
        if(ow == 0){
            vl[v2][v1] = l;
            vt[v2][v1] = t;
        }
    }
    scanf("%d %d", &s, &e);

    shortlen(s, e);
    vector<int> rsp(1, e);
    spdfs(e, 0, rsp);
    reverse(anssp.begin(), anssp.end());
    int distan = 0, ssz = anssp.size();
    for(int i = 0; i < ssz - 1; ++i){
        distan += vl[anssp[i]][anssp[i + 1]];
    }

    shorttime(s, e);
    vector<int> rtp(1, e);
    tpdfs(e, 0, rtp);
    reverse(anstp.begin(), anstp.end());
    int time = 0, tsz = anstp.size();
    for(int i = 0; i < tsz - 1; ++i){
        time += vt[anstp[i]][anstp[i + 1]];
    }

    if(anssp == anstp){
        printf("Distance = %d; Time = %d: ", distan, time);
        for(int i = 0; i < tsz; ++i){
            printf("%d%s", anstp[i], i == tsz - 1 ? "\n" : " -> ");
        }
    }
    else{
        printf("Distance = %d: ", distan);
        for(int i = 0; i < ssz; ++i){
            printf("%d%s", anssp[i], i == ssz - 1 ? "\n" : " -> ");
        }
        printf("Time = %d: ", time);
        for(int i = 0; i < tsz; ++i){
            printf("%d%s", anstp[i], i == tsz - 1 ? "\n" : " -> ");
        }
    }
    return 0;
}
