#include<stdio.h>
#define N 1001
int main()
{
    int i,j,na,nb,nc=0,exp;
    double a[N]={0},c[N+N]={0},coe;
    scanf("%d",&na);
    for(i=0;i<na;i++)
    {
        scanf("%d %lf",&exp,&coe);
        a[exp]=coe;
    }
    scanf("%d",&nb);
    for(i=0;i<nb;i++)
    {
        scanf("%d %lf",&exp,&coe);
        for(j=0;j<N;j++)
        {
            if(a[j]==0)continue;
            c[j+exp]+=coe*a[j];
        }
    }
    for(i=0;i<N+N;i++)if(c[i])nc++;
    printf("%d",nc);
    for(i=N+N-1;i>=0;i--)if(c[i])printf(" %d %.1lf",i,c[i]);
}
