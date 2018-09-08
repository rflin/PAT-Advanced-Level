#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int v = 0):val(v), left(NULL), right(NULL), parent(NULL){}
};
int ino[10000], pre[10000];
map<int, TreeNode*> mp;
TreeNode *build(int preL, int preR, int inoL, int inoR){
    if(preL > preR) return NULL;
    int e = pre[preL], idx = inoL;
    while(e != ino[idx]) ++idx;
    TreeNode *r = new TreeNode(e);
    r->left = build(preL + 1, preL + 1 + idx - 1 - inoL, inoL, idx - 1);
    r->right = build(preR - inoR + idx + 1, preR, idx + 1, inoR);
    if(r->left) r->left->parent = r;
    if(r->right) r->right->parent = r;
    mp[e] = r;
    return r;
}
int getLength(TreeNode *r){
    int k = 1;
    while(r->parent) r = r->parent, ++k;
    return k;
}
TreeNode * LCA(TreeNode *p, TreeNode *q){
    int l1 = getLength(p), l2 = getLength(q);
    while(l1 > l2) p = p->parent, --l1;
    while(l2 > l1) q = q->parent, --l2;
    while(p!=q) p = p->parent, q = q->parent;
    return p;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", ino + i);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", pre + i);
    }
    TreeNode *r = build(0, n - 1, 0, n - 1);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        TreeNode *p = mp.count(x) ? mp[x] : NULL, *q = mp.count(y) ? mp[y] : NULL;
        if(!p&&!q) printf("ERROR: %d and %d are not found.\n", x, y);
        else if(!p || !q) printf("ERROR: %d is not found.\n", p?y:x);
        else {
            TreeNode *res = LCA(p, q);
            if(res != p && res != q ) printf("LCA of %d and %d is %d.\n", x, y, res->val);
            else printf("%d is an ancestor of %d.\n", res == p?x:y, res == p?y:x);
        }
    }
    return 0;
}
