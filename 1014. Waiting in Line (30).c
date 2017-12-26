#include <stdio.h>
int FindEarly(int service[][11],int n,int m)//该函数用于每次找到最早离开的窗口位置pos，并将其后所有元素前移；
{
    int min=9999999,pos;
    for(int i=0;i<n;++i)
    {
        if(min>service[i][0])
        {
            min=service[i][0];
            pos=i;
        }
    }
    for(int i=0;i<m-1;++i)//该用户结束服务离开，后续用户前移
        service[pos][i]=service[pos][i+1];
    return pos;
}
int main()
{
    int n,m,k,q;
    int queue[1001],cur=0;//队列queue以及cur，其中cur用于记录队列首位位置；
    int service[21][11],ans[1001];//service用于窗口时间记录，ans用于记录用户结束用时
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for(int i=0;i<k;++i)
        scanf("%d",&queue[i]);//入队
    int i=0,j=0;
    while(cur<k&&j<m)//该循环用于将队列用户填入各服务窗口
    {
        while(i<n)//填入行
        {
            if(j==0)
                service[i][j]=8*60+queue[cur++];//从八点开始
            else
                service[i][j]=service[i][j-1]+queue[cur++];//从前面用户结束时间开始
            ans[cur-1]=service[i][j];//记录交易完成时间
            ++i;
        }
        i=0;++j;//i=0用于列完成
    }
    while(cur<k)//在黄线外等待的人，如果没有，则不执行该循环
    {
        int pos=FindEarly(service,n,m);//找到最早结束的窗口位置
        service[pos][m-1]+=queue[cur++];//黄线外的人进入服务
        ans[cur-1]=service[pos][m-1];//记录交易完成时间
    }
    while(q--)
    {
        scanf("%d",&i);
        if(ans[i-1]-queue[i-1]<17*60)//筛选开始服务时间小于17点的person
            printf("%02d:%02d\n",ans[i-1]/60,ans[i-1]%60);
        else
            printf("Sorry\n");
    }
    return 0;
}
