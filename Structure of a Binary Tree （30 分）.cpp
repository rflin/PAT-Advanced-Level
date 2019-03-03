#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    TreeNode *left, *right, *parent;
    int val;
    TreeNode(int v = 0):left(NULL), right(NULL), parent(NULL), val(v){}
};
int pos[32], ino[32];
map<int, TreeNode*> mp;
map<int, int> lev;
bool isfull = true;

TreeNode *build(int posL, int posR, int inoL, int inoR, int depth){
    if(posL > posR) return NULL;
    int e = pos[posR], idx = inoL;
    while(e != ino[idx]) ++idx;
    TreeNode *r = new TreeNode(e);
    lev[e] = depth;
    r->left = build(posL, posL + idx - 1 - inoL, inoL, idx - 1, depth + 1);
    r->right = build(posR - 1 -(inoR - idx - 1),posR - 1, idx + 1, inoR, depth + 1);
    if(r->left) r->left->parent = r;
    if(r->right) r->right->parent = r;
    if((!r->left && r->right) || (r->left && !r->right)) isfull = false;
    mp[e] = r;
    return r;
}
void sol(string &s, TreeNode *r){
    if(s.find("root") != string::npos){
        int num;
        sscanf(s.c_str(), "%d is the root", &num);
        r->val == num ? printf("Yes\n"):printf("No\n");
    }
    else if(s.find("siblings") != string::npos){
        int a, b;
        sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
        TreeNode *p = mp[a], *q = mp[b];
        p->parent == q->parent ? printf("Yes\n") : printf("No\n");
    }
    else if(s.find("parent") != string::npos){
        int a, b;
        sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
        TreeNode *p = mp[a], *q = mp[b];
        p == q->parent ? printf("Yes\n") : printf("No\n");
    }
    else if(s.find("left child") != string::npos){
        int a, b;
        sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
        TreeNode *p = mp[a], *q = mp[b];
        p == q->left ? printf("Yes\n") : printf("No\n");
    }
    else if(s.find("right child") != string::npos){
        int a, b;
        sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
        TreeNode *p = mp[a], *q = mp[b];
        p == q->right ? printf("Yes\n") : printf("No\n");
    }
    else if(s.find("level") != string::npos){
        int a, b;
        sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
        lev[a] == lev[b] ? printf("Yes\n") : printf("No\n");
    }
    else if(s.find("full") != string::npos){
        isfull ? printf("Yes\n") : printf("No\n");
    }
}
int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", pos + i);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", ino + i);
    }
    TreeNode *r = build(0, n - 1, 0, n - 1, 1);
    scanf("%d", &m);
    getchar();
    while(m--){
        string s;
        getline(cin, s);
        sol(s, r);
    }
    return 0;
}
