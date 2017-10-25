#include <bits/stdc++.h>
using namespace std;
int ntor,dtor,inter;
int gcd(int a,int b)
{
	if(a==0) return b;
	int r=0;
	while((r=a%b)!=0)
	{
		a=b;
		b=r;
	}
	return b;
}
void simp(int &a,int &b)
{
	int x=gcd(a,b);
	a/=x;
	b/=x;
}
void part(int &a,int &b,int &x)
{
	x=0;
	if(abs(a)<b)
	{
		if(a<0)
		{
			x--;
			a+=b;
		}
		return;
	}
	int sign=a/abs(a);
	a*=sign;
	x=a/b;
	a%=b;
	if(sign==-1)
	{
		x--;
		a=b-a;
	}
}
void add(int a,int b,int x)
{
	ntor=a*dtor+b*ntor;
	dtor*=b;
	int sur=0;
	part(ntor,dtor,sur);
	simp(ntor,dtor);
	inter+=x+sur;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d/%d",&ntor,&dtor);
	part(ntor,dtor,inter);
	simp(ntor,dtor);
	--n;
	for(int i=0;i<n;++i)
	{
		int a,b,x=0;
		scanf("%d/%d",&a,&b);
		part(a,b,x);
		simp(a,b);
		add(a,b,x);
	}
	if(inter)
	{
		printf("%d",inter);
		if(ntor) printf(" %d/%d\n",ntor,dtor);
	}
	else ntor?printf("%d/%d\n",ntor,dtor):printf("0\n");
	return 0;
}
