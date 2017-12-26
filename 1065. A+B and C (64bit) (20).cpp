/*注意溢出判断*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long sum=a+b;
        bool ret;
        if(a<0&&b<0&&sum>=0) ret=0;
        else if(a>0&&b>0&&sum<=0) ret=1;
        else ret=(sum>c)?1:0;
        ret?cout<<"Case #"<<i<<": true\n":cout<<"Case #"<<i<<": false\n";
    }
    return 0;
}
