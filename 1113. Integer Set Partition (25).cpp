#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
using namespace std;
int main()
{
    int n,sum=0;
    vector<int> v;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;++i) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n/2;++i) sum+=v[n-i-1]-v[i];
    n%2==0?cout<<0<<" "<<sum:cout<<1<<" "<<sum+v[n/2];
    return 0;
}
