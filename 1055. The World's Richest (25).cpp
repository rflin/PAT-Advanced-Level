#include <bits/stdc++.h>
using namespace std;
struct node
{
    char name[10];
    int age;
    int worth;
}s[101024];
bool cmp(const node &a,const node &b)
{
    if(a.worth!=b.worth)
        return a.worth>b.worth;
    return a.age==b.age?strcmp(a.name,b.name)<0:a.age<b.age;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    	scanf("%s %d %d",s[i].name,&s[i].age,&s[i].worth);
    sort(s,s+n,cmp);
    for(int i=1;i<=k;i++)
    {
        int m,Amin,Amax,cnt=0;
        scanf("%d %d %d",&m,&Amin,&Amax);
        printf("Case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            if(s[j].age>=Amin&&s[j].age<=Amax)
            {
                printf("%s %d %d\n",s[j].name,s[j].age,s[j].worth);
                cnt++;
            }
            if(cnt==m)break;
        }
        if(cnt==0) printf("None\n");
    }
    return 0;
}
