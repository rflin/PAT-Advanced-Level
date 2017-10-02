/*13的整数倍不用输出tret*/
#include <bits/stdc++.h>
using namespace std;
vector<string> low={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
vector<string> high={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int search(string &val,vector<string> &v)
{
    for(size_t i=0;i<v.size();++i)
        if(v[i]==val) return i;
    return -1;
}
string toMarnum(int n)
{
    int h=n/13,l=n%13;
    if(h)
        return l==0?high[h]:high[h]+" "+low[l];
    return low[l];
}
int toEarnum(string &hs,string &ls)
{
    if(ls!="")
        return search(hs,high)*13+search(ls,low);
    int k=search(hs,low);
    if(k!=-1)
        return k;
    return search(hs,high)*13;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string x,y="";
        cin>>x;
        if(cin.get()==' ') cin>>y;
        if(isdigit(x[0]))
            cout<<toMarnum(stoi(x))<<endl;
        else
            cout<<toEarnum(x,y)<<endl;
    }
    return 0;
}
