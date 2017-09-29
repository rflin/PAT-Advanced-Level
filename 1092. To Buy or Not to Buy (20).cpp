#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> beadscnt(128);
    char ch;
    int pos=0,neg=0;
    while((ch=cin.get())!='\n') beadscnt[ch-'\0']++;
    while((ch=cin.get())!='\n') beadscnt[ch-'\0']--;
    for(auto x:beadscnt)
    {
        if(x>0) pos+=x;
        if(x<0) neg+=x;
    }
    if(neg<0) cout<<"No "<<-neg;
    else cout<<"Yes "<<pos;
    return 0;
}
