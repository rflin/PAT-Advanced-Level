/*
https://www.patest.cn/contests/pat-a-practise/1102
*/
#include <stdio.h>
struct tree//树节点
{
    int left,right;
}node[12];
int findroot[12];
int main()
{
    int n,i;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;++i)
    {
        char l,r;
        scanf("%c %c",&l,&r);
        getchar();
        node[i].left=(l=='-')?-1:l-'0',findroot[l-'0']=1;
        node[i].right=(r=='-')?-1:r-'0',findroot[r-'0']=1;
    }
    while(i>=0&&findroot[--i]);//找根
    int root=i;
    int queue[100],front=0,rear=0,s;
    queue[rear++]=root;
    while(front<rear)//层序遍历
    {
        s=queue[front++];
        if(node[s].right!=-1)
            queue[rear++]=node[s].right;
        if(node[s].left!=-1)
            queue[rear++]=node[s].left;
        front==rear?printf("%d\n",s):printf("%d ",s);
    }
    int stack[100],top=0,c=0;
    s=root;
    while(s!=-1||top)//非递归中序遍历
    {
        while(s!=-1)
        {
            stack[top++]=s;
            s=node[s].right;
        }
        if(top)
        {
            s=stack[--top];
            ++c;
            c==n?printf("%d",s):printf("%d ",s);
            s=node[s].left;
        }
    }
    return 0;
}
