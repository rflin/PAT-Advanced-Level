#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    int left, right, val;
}T[32];
int n, wt[32], rts[32], A[32], levcnt[32];
int notbalan = 0;
bool iscbt = true;
int exchange = 0;

int str2int(string s){
    if(s == "-") return -1;
    int idx = stoi(s);
    rts[idx] = 1;
    return idx;
}
int sol(int r, int i, int deep){
    if(r == -1) return 0;
    levcnt[deep]++;
    int lc = sol(T[r].left, 2 * i, deep + 1);
    int rc = sol(T[r].right, 2 * i + 1, deep + 1);
    if(i <= n) A[i] = wt[r];
    else iscbt = false;
    if(abs(lc - rc) > 1) notbalan++;
    return max(lc, rc) + 1;
}
void adjust(int s, int e){
    int temp = A[s];
    int parent = s, child;
    while(2 * parent <= e){
        child = 2 * parent;
        if(child < e && A[child] < A[child + 1]) ++child;
        if(temp > A[child]) break;
        A[parent] = A[child];
        parent = child;
        ++exchange;
    }
    A[parent] = temp;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &wt[i]);
    }
    for(int i = 1; i <= n; ++i){
        string l, r;
        cin >> l >> r;
        T[i].left = str2int(l);
        T[i].right = str2int(r);
    }
    int root = 1;
    while(rts[root] > 0) ++root;
    sol(root, 1, 1);
    if(notbalan > 0){
        printf("NOT AVL TREE!!!\n%d", notbalan);
        return 0;
    }
    if(!iscbt){
        int lastlay = 1, laynums = 1;
        while(levcnt[lastlay] == laynums) lastlay++, laynums *= 2;
        printf("NOT COMPLETE TREE!!!\n%d", lastlay - 1);
        return 0;
    }
    for(int i = n / 2; i >= 1; --i){
        adjust(i, n);
    }
    printf("OHHHHH HEAP!!!\n%d", exchange);
    return 0;
}
