#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,pre=0,cur,cnt=0;
    cin>>n;
    while(n--)
    {
        cin>>cur;
        if(cur>pre) cnt+=6*(cur-pre);
        else if(cur<pre) cnt+=4*(pre-cur);
        pre=cur;
        cnt+=5;
    }
    cout<<cnt;
    return 0;
}
