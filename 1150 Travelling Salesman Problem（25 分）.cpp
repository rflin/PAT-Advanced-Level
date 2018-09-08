#include <bits/stdc++.h>
using namespace std;
int A[256][256], n, m;
int mindis = 0x7fffffff, z = -1;
void TSPsol(vector<int> &v, int ith){
    printf("Path %d: ", ith);
    bool visit[256] = {};
    int sz = v.size(), isSim = 1, dis = 0;
    for(int i = 0; i < sz - 1; ++i){
        if(A[v[i]][v[i + 1]] == 0){
            // printf("%d %d %d\n", v[i], v[i+1], A[v[i]][v[i + 1]]);
            printf("NA (Not a TS cycle)\n");
            return;
        }
        if(visit[v[i]]) isSim = 0;
        visit[v[i]] = 1;
        dis += A[v[i]][v[i + 1]];
    }
    int visNums = accumulate(visit + 1, visit + n + 1, 0);
    if(visNums == n && isSim && v[0] == v.back()){
        printf("%d (TS simple cycle)\n", dis);
        if(dis < mindis) mindis = dis, z = ith;
    }
    else if(visNums == n && !isSim && v[0] == v.back()){
        printf("%d (TS cycle)\n", dis);
        if(dis < mindis) mindis = dis, z = ith;
    }
    else printf("%d (Not a TS cycle)\n", dis);
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int x, y, c;
        scanf("%d %d %d",&x, &y, &c);
        A[x][y] = A[y][x] = c;
    }
    int w = 1, q = 0;
    scanf("%d", &q);
    while(q--){
        int k, val;
        scanf("%d", &k);
        vector<int> v;
        while(k--){
            scanf("%d", &val);
            v.push_back(val);
        }
        TSPsol(v, w++);
    }
    printf("Shortest Dist(%d) = %d\n", z, mindis);
    return 0;
}
