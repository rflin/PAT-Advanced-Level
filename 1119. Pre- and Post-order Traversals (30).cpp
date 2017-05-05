/*
分析：
1、前、中、后，不论以何种方式进行遍历，我们始终能对这一序列作出一个划分，比如前序遍历为：【父节点】、【左子树】、【右子树】
2、对于前序和中序，众所周知，能唯一确定一棵二叉树，这是因为，对于前序中的父节点，在中序序列中始终体现为：
在该点的左边，为该节点的左子树，在该点的右边，为该节点的右子树，因此，整棵树确定了；
3、对于此题，题目告诉了前序和后序，不能唯一确定一颗二叉树，这是因为，对于子树的划分我们不是很明确，可能为左子树，也可能为右子树，
正如测试2你所看到的那样.

解题思路：
1、递归求解即可，本代码将结果保存于in数组中；
2、注意递归出口条件；
3、注意unique的判定；
*/
#include <iostream>
using namespace std;
int pre[30],post[30],in[30],k=0;
bool unique=true;
void Solve(int prL,int prR,int poL,int poR)//递归建树
{
    if(prL>prR||poL>poR)return;
    if(prL==prR)
    {
        in[k++]=pre[prL];return;
    }
    else if(poL==poR)
    {
        in[k++]=pre[poR];return;
    }
    int e=pre[prL+1],i=poL;
    while(post[i]!=e&&i<=poR-1)++i;
    if(i==poR-1) unique=false;
    Solve(prL+1,prL+1+i-poL,poL,i);
    in[k++]=pre[prL];
    Solve(prL+1+i-poL+1,prR,i+1,poR-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>pre[i];//前序遍历
    for(int i=0;i<n;++i) cin>>post[i];//后序遍历
    Solve(0,n-1,0,n-1);
    if(unique)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=0;i<n;++i)//输出中序遍历
    {
        i==n-1?cout<<in[i]<<endl:cout<<in[i]<<" ";
    }
    return 0;
}
