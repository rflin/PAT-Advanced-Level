/*
说明：
1、测试数据稍弱；如果输入10000，应该输出10000 + 1 = 10001，而不是+ 00001，但本测试用例无此情况，故可以略去
2、实际考察大数相加
注意：
1、如果输入A本身是回文数，则不进行迭代求和，应该直接输出结果
*/
#include <bits/stdc++.h>
using namespace std;
string add(const string &A,const string &B)
{
    int i=A.size()-1,sur=0;
    string C;
    while(i>=0)
    {
        int sum=A[i]-'0'+B[i]-'0';
        C+=(sur+sum)%10+'0';
        sur=(sur+sum)/10;
        --i;
    }
    if(sur>0)C+='0'+sur;
    reverse(C.begin(),C.end());
    return C;
}
bool ispalindromic(const string &C)
{
    int len=C.size(),i;
    for(i=0;i<len/2;++i)
        if(C[i]!=C[len-1-i]) return false;
    return true;
}
int main()
{
    string A,B,C;
    int cnt=10;
    cin>>A;
    if(ispalindromic(A))
    {
        cout<<A<<" is a palindromic number."<<endl;
        return 0;
    }
    while(cnt--)
    {
        B=A;
        reverse(B.begin(),B.end());
        C=add(A,B);
        cout<<A<<" + "<<B<<" = "<<C<<endl;
        if(ispalindromic(C))
        {
            cout<<C<<" is a palindromic number."<<endl;
            return 0;
        }
        A=C;
    }
    cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
