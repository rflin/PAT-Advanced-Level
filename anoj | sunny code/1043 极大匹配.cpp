#include <bits/stdc++.h>

using namespace std;

vector<int> v[1024];
int n, m;

void sol(map<int, int> &vmp){
    vector<int> visit(n + 1, 0);
    for(auto e: vmp){
        if(e.second > 1){
            printf("Not a Matching\n");
            return;
        }
        visit[e.first] = 1;
    }
    for(int i = 1; i <= n; ++i){
        if(visit[i] == 0){
            for(int x: v[i]){
                if(visit[x] == 0){
                    printf("Not Maximal\n");
                    return;
                }
            }
        }
    }
    printf("Yes\n");
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;
    scanf("%d", &k);
    while(k--){
        int l;
        map<int, int> vmp;
        scanf("%d", &l);
        for(int i = 0; i < l; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            vmp[a]++;
            vmp[b]++;
        }
        sol(vmp);
    }
    return 0;
}
