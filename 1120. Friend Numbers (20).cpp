#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
#include <string> 
using namespace std;
int main()
{
    int n;
    map<int,bool> m;
    cin>>n;
    while(n--)
    {
    	int k,sum=0;
    	cin>>k;
    	while(k)
    	{
    		sum+=k%10;
    		k/=10;
		}
		m[sum]=true;
	}
	auto x=m.end();
	x--;
	cout<<m.size()<<endl;
	for(auto it=m.begin();it!=m.end();++it)it==x?cout<<it->first:cout<<it->first<<" ";
    return 0;
}
