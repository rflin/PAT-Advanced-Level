#include <bits/stdc++.h>
int hash[11024];
int isprime(int n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;++i)
        if(n%i==0) return false;
    return true;
}
int main()
{
    int msize,n;
    scanf("%d %d",&msize,&n);
    while(!isprime(msize))
        ++msize;
    while(n--)
    {
        int e,i;
        scanf("%d",&e);
        for(i=0;i<msize;++i)
        {
            if(!hash[(e+i*i)%msize])
            {
                hash[(e+i*i)%msize]=e;
                printf("%d",(e+i*i)%msize);
                break;
            }
        }
        if(i==msize)printf("-");
        if(n)printf(" ");
    }
    return 0;
}
