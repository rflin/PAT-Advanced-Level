#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct mooncake
{
    double amount;
    double price;
    mooncake(double amt=0,double p=0.0):amount(amt),price(p){}
    bool operator >(const mooncake &a) const
    {
        return price/amount>a.price/a.amount;
    }
};
vector<mooncake> v;
int main()
{
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;++i)
    {
        double amt;
        cin>>amt;
        v.push_back(mooncake(amt));
    }
    for(int i=0;i<n;++i)
    {
        double p;
        cin>>p;
        v[i].price=p;
    }
    sort(v.begin(),v.end(),greater<mooncake>());
    double profit=0.0;
    int i=0;
    while(d>0&&i<n)
    {
        if(v[i].amount<=d)
        {
            profit+=v[i].price;
            d-=v[i++].amount;
        }
        else
        {
            profit+=v[i].price/v[i].amount*d;
            d=0;
        }
    }
    printf("%.2lf\n",profit);
    return 0;
}
