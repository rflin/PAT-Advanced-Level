#include <bits/stdc++.h>
using namespace std;

pair<double,int> searchMax(double a,double b,double c)
{
	double m=max(max(a,b),c);
	return m==a?pair<double,int>(a,0):
	m==b?pair<double,int>(b,1):pair<double,int>(c,2);
}
int main()
{
	double ret=1.0;
	string w="WTL",ans;
	for(int i=0;i<3;++i)
	{
		double a,b,c;
		cin>>a>>b>>c;
		auto maxp=searchMax(a,b,c);
		ans+=w[maxp.second]+string(" ");
		ret*=maxp.first;
	}
	cout<<ans;
	printf("%.2lf\n",(ret*0.65-1)*2+0.000000001);
	return 0;
}
