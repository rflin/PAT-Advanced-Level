#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
struct Rational
{
	llt i,a,b;
	Rational(llt ix,llt ax,llt bx):i(ix),a(ax),b(bx){}
	Rational operator + (const Rational &val)
	{
		Rational result(i+val.i,a*val.b+b*val.a,b*val.b);
		result.simplify();
		return result;
	}
	Rational operator - (const Rational &val)
	{
		Rational result(i-val.i,a*val.b-b*val.a,b*val.b);
		result.simplify();
		return result;
	}
	Rational operator * (const Rational &val)
	{
		Rational A(0,i*b+a,b),B(0,val.i*val.b+val.a,val.b);
		Rational result(0,A.a*B.a,A.b*B.b);
		result.simplify();
		return result;
	}
	Rational operator / (const Rational &val)
	{
		Rational A(0,i*b+a,b),B(0,val.i*val.b+val.a,val.b);
		Rational result(0,A.a*B.b,A.b*B.a);
		if(result.b<0) result.a*=-1,result.b*=-1;
		result.simplify();
		return result;
	}
	void simplify()
	{
		i+=a/b,a%=b;
		llt v=abs(__gcd(a,b));
		a/=v,b/=v;
		if(i<0&&a>0) i+=1,a-=b;
	}
	string r2str()
	{
		string ret;
		if(i&&a) ret=to_string(i)+" "+to_string(abs(a))+"/"+to_string(b);
		else if(!i&&a) ret=to_string(a)+"/"+to_string(b);
		else ret=to_string(i);
		return i<0||a<0?"("+ret+")":ret;
	}
};
void showEquation(Rational &r1,Rational &r2,Rational res,char op)
{
	string ans=r1.r2str()+" "+op+" "+r2.r2str()+" = "+res.r2str();
	printf("%s\n",ans.c_str());
}
int main()
{
	Rational r1(0,0,1),r2(0,0,1);
	scanf("%lld/%lld %lld/%lld",&r1.a,&r1.b,&r2.a,&r2.b);
	r1.simplify(),r2.simplify();
	showEquation(r1,r2,r1+r2,'+');
	showEquation(r1,r2,r1-r2,'-');
	showEquation(r1,r2,r1*r2,'*');
	if(!r2.i&&!r2.a)
	{
		string ans=r1.r2str()+" / "+r2.r2str()+" = Inf";
		printf("%s\n",ans.c_str());
	}
	else showEquation(r1,r2,r1/r2,'/');
	return 0;
}
