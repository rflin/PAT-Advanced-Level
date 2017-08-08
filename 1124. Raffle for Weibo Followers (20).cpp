/*
https://www.patest.cn/contests/pat-a-practise/1124
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    int m,n,s;
    vector<string> v;
    map<string,int> check;
    cin>>m>>n>>s;
    for(int i=1;i<=m;++i)
    {
        string str;
        cin>>str;
        v.push_back(str);
        check[str]=0;
    }
    if(v.size()<(unsigned int)s)
    {
        cout<<"Keep going..."<<endl;
    }
    else
    {
        while(s<=m)
        {
            if(check[v[s-1]]==0)
            {
                check[v[s-1]]=1;
                cout<<v[s-1]<<endl;
            }
            else
            {
                while(s<=m&&check[v[s-1]]==1) ++s;
                if(s>m) break;
                else
                {
                    check[v[s-1]]=1;
                    cout<<v[s-1]<<endl;
                }
            }
            s+=n;
        }
    }
    return 0;
}
