#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int n1,n2,n3;
    cin>>a;
    int n=a.size();
    n2=3;
    n1=n3=(n-n2+2)/2;
    while(n2<=n&&(n1+n2+n3-2!=n||n1>n2))
    {
        ++n2;
        n1=n3=(n-n2+2)/2;
    }
    string ans;
    for(int i=0;i<n1-1;++i)
        ans+=a[i]+string(n2-2,' ')+a[n-1-i]+'\n';
    ans+=a.substr(n1-1,n2);
    cout<<ans<<endl;
    return 0;
}
