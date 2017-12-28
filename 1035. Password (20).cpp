#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<string> v;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string name,password,temppass;
        cin>>name>>password;
        temppass=password;
        for(auto &x:password)
        {
            if(x=='1')x='@';
            if(x=='0')x='%';
            if(x=='l')x='L';
            if(x=='O')x='o';
        }
        if(password!=temppass)
            v.push_back(name+" "+password);

    }
    if(v.size()>0)
    {
        cout<<v.size()<<endl;
        for(auto &x:v)
            cout<<x<<endl;
    }
    else
    {
        if(n==1) cout<<"There is 1 account and no account is modified"<<endl;
        else cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    return 0;
}
