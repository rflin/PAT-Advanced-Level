#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int key=sqrt((double)n);//因子上限
    int s,maxlen=0;
    for(int i=2;i<=key;++i)//因子范围
    {
        int m=n;
        int curlen=0;
        int k=i;
        while(m%k==0)//找连续因子
        {
            ++curlen;
            m/=k;++k;
        }
        if(curlen>maxlen)//记录最大连续长度和开始因子
        {
            maxlen=curlen;
            s=i;
        }
    }
    if(!maxlen)
    {
        printf("1\n%d",n);return 0;
    }
    printf("%d\n%d",maxlen,s);
    while(--maxlen)
    {
        printf("*%d",++s);
    }
    return 0;
}
