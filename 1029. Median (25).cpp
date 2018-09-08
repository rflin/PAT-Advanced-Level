#include <bits/stdc++.h>
using namespace std;

int A[200000], n, m;
int i, j, k, mid, val, res;

int main()
{
    // freopen("1.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", A + i);
    }
    scanf("%d", &m);
    mid = (m + n - 1) / 2 + 1;
    scanf("%d", &val);
    while(i < n && j < m && k != mid){
        if(A[i] < val) res = A[i++];
        else res = val, ++j, scanf("%d", &val);
        ++k;
    }
    while(i < n && k != mid){
        res = A[i++];
        ++k;
    }
    while(j < m && k != mid){
        res = val;
        ++j;
        scanf("%d", &val);
        ++k;
    }
    printf("%d\n", res);
    return 0;
}
