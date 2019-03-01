#include <bits/stdc++.h>

using namespace std;
int birdsnum = -1;
int parents[11024];
int finds(int x){
    return x == parents[x] ? x: parents[x] = finds(parents[x]);
}
int main()
{
    int n;
    for(int i = 1; i <= 10000; ++i) parents[i] = i;
    scanf("%d", &n);
    vector<int> lead(n);
    for(int i = 0; i < n; ++i){
        int k;
        scanf("%d %d", &k, &lead[i]);
        birdsnum = max(birdsnum, lead[i]);
        k--;
        while(k--){
            int x;
            scanf("%d", &x);
            birdsnum = max(birdsnum, x);
            int L1 = finds(lead[i]), L2 = finds(x);
            if(L1 != L2) parents[L2] = L1;
        }
    }
    map<int, int> cnt;
    for(int i = 0; i < n; ++i){
        cnt[finds(lead[i])] = 1;
    }
    printf("%d %d\n", (int)cnt.size(), birdsnum);
    int q;
    scanf("%d", &q);
    while(q--){
        int x, y;
        scanf("%d %d", &x, &y);
        int L1 = finds(x), L2 = finds(y);
        if(L1 != L2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
