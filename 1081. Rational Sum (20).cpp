#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
struct Rational
{
	llt i,a,b;
	Rational(llt _i,llt _a,llt _b):i(_i),a(_a),b(_b){}
	Rational & operator +=(const Rational &val)
	{
		llt x=a*val.b+b*val.a,y=b*val.b;
		i+=val.i+x/y;
		a=x%y;
		b=y;
		simplify();
		return *this;
	}
	void simplify()
	{
		llt v=abs(__gcd(a,b));
		a/=v,b/=v;
		if(a<0) i-=1,a+=b;
	}
};
int main()
{
	int n;
	Rational result(0,0,1);
	scanf("%d",&n);
	while(n--)
	{
		Rational val(0,0,1);
		scanf("%lld/%lld",&val.a,&val.b);
		val.simplify();
		result+=val;
	}
	if(result.i&&result.a)
		printf("%lld %lld/%lld\n",result.i,result.a,result.b);
	else if(!result.i&&result.a)
		printf("%lld/%lld\n",result.a,result.b);
	else printf("%lld\n",result.i);
	return 0;
}
