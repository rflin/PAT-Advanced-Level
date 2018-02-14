/*考察字符串哈希*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mp[26*26*26*10];
int str2int(char name[])
{
    int idx=0;
    for(int i=0;i<3;++i)
        idx=idx*26+(name[i]-'A');
    return idx*10+name[3]-'0';
}
int main()
{
    int n,k;
    char name[8];
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;++i)
    {
        int courseNum,count;
        scanf("%d %d",&courseNum,&count);
        while(count--)
        {
            scanf("%s",name);
            int idx=str2int(name);
            mp[idx].push_back(courseNum);
        }
    }
    while(n--)
    {
        scanf("%s",name);
        int idx=str2int(name);
        vector<int> &v=mp[idx];
        sort(v.begin(),v.end());
        printf("%s %lld",name,v.size());
        for(auto x:v)
            printf(" %d",x);
        printf("\n");
    }
    return 0;
}
