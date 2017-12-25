#include <bits/stdc++.h>
using namespace std;
map<int,set<int>> mp;
int convertToint(char name[])
{
    int ret=0;
    for(int i=0;i<3;++i)
        ret=ret*100+(name[i]-'A');
    return ret*10+name[3];
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;++i)
    {
        int coursei,studentn;
        scanf("%d %d",&coursei,&studentn);
        while(studentn--)
        {
            char name[8];
            scanf("%s",name);
            int ret=convertToint(name);
            mp[ret].insert(coursei);
        }
    }
    while(n--)
    {
        char name[8];
        scanf("%s",name);
        int ret=convertToint(name);
        printf("%s %lld",name,mp[ret].size());
        for(auto x:mp[ret])
            cout<<" "<<x;
        cout<<endl;
    }
    return 0;
}
