#include <bits/stdc++.h>

using namespace std;

stack<int> stk;
int n;
vector<int> pre, ino, pos;

void build(int preL, int preR, int inoL, int inoR){
    if(preL > preR) return;
    int e = pre[preL], idx = inoL;
    while(e != ino[idx]) ++idx;
    build(preL + 1, preL + 1 + idx - 1 - inoL, inoL, idx - 1);
    build(preR - inoR + idx + 1, preR, idx + 1, inoR);
    pos.push_back(e);
}
int main()
{
    cin >> n;
    for(int i = 0; i < 2 * n; ++i){
        string op;
        cin >> op;
        if(op == "Push"){
            int val;
            cin >> val;
            stk.push(val);
            pre.push_back(val);
        }
        else{
            ino.push_back(stk.top());
            stk.pop();
        }
    }
    build(0, n - 1, 0, n - 1);
    int sz = pos.size();
    for(int i = 0; i < sz; ++i){
        printf("%d%c", pos[i], i == n - 1 ? '\n': ' ');
    }
    return 0;
}
