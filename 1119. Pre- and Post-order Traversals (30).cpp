/*
分析：对于前序和中序，或者后序和中序，可以唯一确定一棵二叉树，而对于前序和后序，可能不能唯一确定一棵二叉树，原因在于，
前序和后序对于左右子树的划分可能是不确定的。并且这种不确定，只可能出现在具有单一子树的节点中，这是因为，建树过程中，将
该子树放在左边，或者右边，都是可以的，因为这两种方式都将产生相同的前序和后序序列。因此，判断其是否unique便依据于此：倘
若在一次递归建树中，位于前序序列的第二个元素（是第一个元素的子树根节点，左儿子或者右儿子），和后序序列中倒数第二个元素相
同，这意味者，对于根节点来说（前序第一个元素），其只有一个儿子（要么是左儿子，要么是右儿子），这将不是unique的。
*/
#include <bits/stdc++.h>
using namespace std;
int pre[32], pos[32];
vector<int> ino;
bool isunique = true;
void build(int preL, int preR, int posL, int posR){
    if(preL > preR) return;
    if(preL == preR){
        ino.push_back(pre[preL]);
        return;
    }
    int e = pre[preL + 1], posidx = posL;
    while(pos[posidx] != e) ++posidx;
    if(posidx == posR - 1) isunique = false;
    build(preL + 1, posidx - posL + preL + 1, posL, posidx);
    ino.push_back(pre[preL]);
    build(preR - (posR - 1 - posidx - 1), preR, posidx + 1, posR - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &pos[i]);
    }
    build(0, n - 1, 0, n - 1);
    printf("%s\n", isunique ? "Yes" : "No");
    for(int i = 0; i < n; ++i){
        printf("%d%c", ino[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}

