/*
题意：两个数组，每个元素只能用一次，使得他们乘积和最大
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vp1,vn1,vp2,vn2;
    long money=0;
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x>=0) vp1.push_back(x);
        else vn1.push_back(x);
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x>=0) vp2.push_back(x);
        else vn2.push_back(x);
    }
    sort(vp1.begin(),vp1.end(),greater<int>());//正数
    sort(vn1.begin(),vn1.end());//负数
    sort(vp2.begin(),vp2.end(),greater<int>());//正数
    sort(vn2.begin(),vn2.end());//负数
    auto itvp1=vp1.begin();
    auto itvp2=vp2.begin();
    while(!vp1.empty()&&itvp1!=vp1.end()&&!vp2.empty()&&itvp2!=vp2.end())
        money+=(*itvp1++)*(*itvp2++);
    auto itvn1=vn1.begin();
    auto itvn2=vn2.begin();
    while(!vn1.empty()&&itvn1!=vn1.end()&&!vn2.empty()&&itvn2!=vn2.end())
        money+=(*itvn1++)*(*itvn2++);
    printf("%ld",money);
    return 0;
}
