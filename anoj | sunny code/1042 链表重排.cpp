#include <bits/stdc++.h>

using namespace std;

struct node{
    int addr, val, next;
    node(int a = 0, int v = 0, int n = 0): addr(a), val(v), next(n){}
}v[100000];

int getlen(int head)
{
    int p = head, len = 0;
    while(p != -1){
        len++;
        p = v[p].next;
    }
    return len;
}
int mk(int head, int m, vector<node> &vx){
    int p = head;
    while(m--){
        vx.push_back(v[p]);
        p = v[p].next;
    }
    return p;
}
int main()
{
    int n, head;
    scanf("%d %d", &n, &head);
    if(head == -1){
        printf("0 -1");
        return 0;
    }
    for(int i = 0; i < n; ++i){
        int addr, val, next;
        scanf("%d %d %d", &addr, &val, &next);
        v[addr] = node(addr, val, next);
    }
    int len = getlen(head);
    int m1 = (len + 1) / 2, m2 = len - m1;
    vector<node> v1, v2, vres;
    int p = mk(head, m1, v1);
    mk(p, m2, v2);
    reverse(v2.begin(), v2.end());
    int i = 0, j = 0;
    while(i < m1 && j < m2){
        vres.push_back(v1[i++]);
        vres.push_back(v2[j++]);
    }
    while(i < m1) vres.push_back(v1[i++]);
    while(j < m2) vres.push_back(v2[j++]);
    int sz = vres.size();
    printf("%d %05d\n", sz, vres[0].addr);
    for(int i = 0; i < sz - 1; ++i){
        printf("%05d %d %05d\n", vres[i].addr, vres[i].val, vres[i + 1].addr);
    }
    printf("%05d %d -1", vres[sz - 1].addr, vres[sz - 1].val);
    return 0;
}
