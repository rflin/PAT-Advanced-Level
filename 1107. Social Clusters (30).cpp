#include <bits/stdc++.h>

using namespace std;

int persHob[1024];

int finds(int x, vector<int> &parents){
    return x == parents[x] ? x: parents[x] = finds(parents[x], parents);
}
int main()
{
    vector<int> parents(1024);
    for(int i = 1; i <= 1000; ++i){
        parents[i] = i;
    }
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int k, fir;
        scanf("%d: %d", &k, &fir);
        persHob[i] = fir;
        --k;
        while(k--){
            int x;
            scanf("%d", &x);
            int L1 = finds(fir, parents);
            int L2 = finds(x, parents);
            if(L1 != L2) parents[L2] = L1;
        }
    }
    map<int, int> cnts;
    for(int i = 1; i <= n; ++i){
        int L = finds(persHob[i], parents);
        cnts[L]++;
    }
    vector<int> res;
    for(auto e: cnts){
        res.push_back(e.second);
    }
    sort(res.begin(), res.end(), greater<int>());
    int sz = res.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i){
        printf("%d%c", res[i], i == sz - 1 ? '\n' : ' ');
    }
    return 0;
}
