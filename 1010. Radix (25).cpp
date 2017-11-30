/*感谢nuaajeff提出的issue，已修正，于2017/11/30*/
#include <bits/stdc++.h>
using namespace std;
long long val(char ch)
{
	return isdigit(ch)?ch-'0':ch-'a'+10;
}
long long toDecimal(string &v,long long radix)
{
	long long a=0;
	for(auto x:v) a=a*radix+val(x);
	return a;
}
long long minRadix(string &v)
{
	long long r=0;
	for(auto x:v) r=max(r,val(x));
	return r+1;
}
long long compare(long long a,string &b,long long radix)
{
	long long m=0;
	for(auto x:b)
	{
		m=m*radix+val(x);
		if(m>a||m<0) return 1;//注意可能溢出变为负值，测试点3
	}
	return m==a?0:-1;
}
long long searchRadix(long long a,string &b)
{
	long long l=minRadix(b),r=max(a,l)+1,ret=-1;
	while(l<=r)
	{
		long long mid=(l+r)/2,k=compare(a,b,mid);
		if(k==0) ret=mid,r=mid-1;
		else if(k<0) l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main()
{
	string n1,n2;
	long long tag,radix;
	cin>>n1>>n2>>tag>>radix;
	if(tag==2) swap(n1,n2);
	long long a=toDecimal(n1,radix);
	long long ret=searchRadix(a,n2);
	if(ret==-1) cout<<"Impossible";
	else cout<<ret;
	return 0;
}
