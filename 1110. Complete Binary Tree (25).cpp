#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int left, right;
};
TreeNode T[32];

bool rts[32], visit[32];

int mk(string l){
    return l == "-" ? -1 : stoi(l);
}
void iscbt(int root){
    queue<int> q;
    q.push(root);
    visit[root] = 1;
    int last = root;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(s == -1) break;
        last = s;
        q.push(T[s].left);
        q.push(T[s].right);
    }
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(s != -1){
            cout << "NO" << " " << root << endl;
            return;
        }
    }
    cout << "YES" << " " << last << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string lft, rgt;
        cin >> lft >> rgt;
        T[i].left = mk(lft);
        T[i].right = mk(rgt);
        if(T[i].left != -1) rts[T[i].left] = 1;
        if(T[i].right != -1) rts[T[i].right] = 1;
    }
    int root = 0;
    while(rts[root]) ++root;
    iscbt(root);
    return 0;
}
