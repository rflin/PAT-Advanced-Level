/*
https://www.patest.cn/contests/pat-a-practise/1125
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    vector<double> v;
    cin>>n;
    while(n--)
    {
        double t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),greater<double>());
    while(v.size()!=1)
    {
        double m,n;
        m=v.back();
        v.pop_back();
        n=v.back();
        v.pop_back();
        v.push_back((m+n)/2);
    }
    cout<<(int)v[0];
    return 0;
}
