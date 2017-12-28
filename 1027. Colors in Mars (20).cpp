#include <bits/stdc++.h>
using namespace std;
vector<char> val={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
string convert(int num)
{
    if(num==0)return string("00");
    string ret;
    while(num)
    {
        ret+=val[num%13];
        num/=13;
    }
    reverse(ret.begin(),ret.end());
    return ret.size()==1?"0"+ret:ret;
}
int main()
{
    string ret="#";
    int k=3;
    while(k--)
    {
        int num;
        cin>>num;
        ret+=convert(num);
    }
    cout<<ret<<endl;
    return 0;
}
