#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int idx;
        cin>>idx;
        int len=to_string(idx).size()/2,base=1;
        while(len--) base*=10;
        int c=(idx/base)*(idx%base);
        if(c&&idx%c==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
